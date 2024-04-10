#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 300001; 

vector<vi> graph(MX);
int N, M;

vi getPath(int v, int u) {
    int lst[N]; F0R(i, N) lst[i] = -1;
    lst[v] = v;
    queue<int> q; q.push(v);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        trav(a, graph[x]) {
            if (lst[a] == -1) {
                lst[a] = x; q.push(a);
            }
        }
    }
    vi res;
    int cur = u; 
    res.pb(u);
    while (lst[cur] != cur) {
        cur = lst[cur];
        res.pb(cur);
    }
    reverse(all(res)); return res;
}

vector<vi> cg(MX);
const pair<int, vector<pi>> DEF = {-1, {}};
void solve() {
    cin >> N >> M;
    vector<pair<int, vector<pi>>> curEd(N);
    F0R(i, N) {
        curEd[i] = {-1, {}};
    }
    F0R(i, M) {
        int U, V; cin >> U >> V; U--; V--;
        graph[U].pb(V); graph[V].pb(U);
    }

    int Q; cin >> Q;
    vector<pair<pi, int>> qs(Q);
    vector<set<int>> qp(N);
    F0R(i, Q) {
        cin >> qs[i].f.f >> qs[i].f.s;
        qs[i].f.f--; qs[i].f.s--;
        qs[i].s = i;
        qp[qs[i].f.f].ins(i);
        qp[qs[i].f.s].ins(i);
        
    }
    int cnt = 0;
    F0R(i, N) cnt += sz(qp[i])%2;
    if (cnt) {
        cout << "NO" << nl; cout << cnt/2 << nl; return;
    }
    vector<vi> res(Q);
    int x = -1, y = -1;
    int p = 0;
    F0R(iter, Q) {
        int qx = -1;
        if (x == -1) {
            while (sz(qp[p]) == 0) {
                p++;
            }
            qx = *qp[p].begin();
        } else {
            if (sz(qp[x])) {
                qx = *qp[x].begin();
            } else qx = *qp[y].begin();
        }
        //dbg(qx);
        int X = qs[qx].f.f; int Y = qs[qx].f.s;
        qp[X].erase(qx); qp[Y].erase(qx);
        if (curEd[X].f == Y) {
            F0R(i, N) cg[i].clear();
            trav(a, curEd[X].s) {
                cg[a.f].pb(a.s); cg[a.s].pb(a.f);
            }
            vi cur;
            int v = X;
            int lst = -1;
            cur.pb(v);
            while (v != Y) {
                int u = -1;
                trav(a, cg[v]) {
                    if (a != lst) u = a;
                }
                cur.pb(u);
                lst = v;
                v = u;
                assert(sz(cur) < 3*N);
            }
            res[qx] = (cur);
            curEd[X] = DEF;
            curEd[Y] = DEF;
            x = -1; y = -1;
        } else if (curEd[X].f != -1 && curEd[Y].f != -1) {
            assert(false);
            vi pth = getPath(X, Y);
            set<pi> cur;
            F0R(i, sz(pth) - 1) {
                pi v = {pth[i], pth[i+1]};
                if (v.f > v.s) swap(v.f, v.s);
                cur.ins(v);
            }
            res[qx] = (pth);
            trav(a, curEd[curEd[X].f].s) {
                if (cur.count(a)) {
                    cur.erase(a);
                } else cur.ins(a);
            }
            trav(a, curEd[curEd[Y].f].s) {
                if (cur.count(a)) {
                    cur.erase(a);
                } else cur.ins(a);
            }
            vpi vs; trav(a, cur) vs.pb(a);
            assert(sz(vs) < 3*N);
            curEd[curEd[X].f] = {curEd[Y].f, vs};
            curEd[curEd[Y].f] = {curEd[X].f, vs};
            curEd[X] = DEF;
            curEd[Y] = DEF;
            x = curEd[X].f; y = curEd[Y].f;
        } else if (curEd[X].f != -1 || curEd[Y].f != -1) {
            bool needRev = false;
            if (curEd[X].f == -1) {
                swap(X, Y); needRev = true;
            }
            F0R(i, N) cg[i].clear();
            trav(a, curEd[X].s) {
                cg[a.f].pb(a.s); cg[a.s].pb(a.f);
            }
            vi cp;
            int v = X;
            int lst = -1;
            cp.pb(v);
            while (v != curEd[X].f) {
                int u = -1;
                trav(a, cg[v]) {
                    if (a != lst) u = a;
                }
                cp.pb(u);
                lst = v;
                v = u;
                assert(sz(cp) < 3*N);
            }
            set<int> inCP; trav(a, cp) inCP.ins(a);
            vi pth = getPath(Y, X);
            reverse(all(cp));


            vi pth2;
            trav(a, pth) {

                if (inCP.count(a)) {
                    bool found = false;
                    trav(b, cp) {
                        if (b == a) found = true;
                        if (found) pth2.pb(b);
                    }
                    break;
                } 
                pth2.pb(a);
            }
            //dbg(cp, pth, pth2);

            pth = pth2;
            if (!needRev) reverse(all(pth));
            vector<pi> cur;
            F0R(i, sz(pth) - 1) {
                pi v = {pth[i], pth[i+1]};
                if (v.f > v.s) swap(v.f, v.s);
                cur.pb(v);
            }
            res[qx] = (pth);

            if (curEd[X].f == -1) {
                swap(X, Y);
            }

            int Z = curEd[X].f;
            set<pi> res2;
            trav(a, cur) {
                res2.ins(a);
            }
            trav(a, curEd[Z].s) {
                if (!res2.count(a)) {
                    res2.ins(a);
                } else res2.erase(a);
            }
            vector<pi> vs; trav(a, res2) vs.pb(a);
            assert(sz(vs) < 3*N);

            curEd[Z] = {Y, vs};
            curEd[X] = DEF;
            curEd[Y] = {Z, vs};
            x = Y; y = Z;

        } else {
            vi pth = getPath(X, Y);
            vector<pi> cur; 
            F0R(i, sz(pth) - 1) { 
                pi v = {pth[i], pth[i+1]};
                if (v.f > v.s) swap(v.f, v.s);
                cur.pb(v);
            }
            res[qx] = (pth);
            assert(sz(pth) < 3*N);
            curEd[X] = {Y, cur};
            curEd[Y] = {X, cur};
            x = X; y = Y;
        }
        /*dbg(X, Y, x, y);
        dbg(qx, res[qx]);
        F0R(i, N) {
            dbg(i, curEd[i].f, curEd[i].s);
        }*/
    }

    int ans = 0;
    F0R(i, N) if (curEd[i].f != -1) ans++;
    if (ans) {
        cout << "NO " << nl << ans/2 << nl;
    } else {
        cout << "YES" << nl;
        trav(a, res) {
            cout << sz(a) << nl;
            trav(b, a) {
                cout << b+1 << " ";
            }
            cout << nl;
        }
    }



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}