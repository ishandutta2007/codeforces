#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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
const int MX = 100001; 

const int K = 320;

int N, Q;
ll ans[K][K];
set<int> pos[MX];
int nxt[MX];
int lst[MX];
bool fl;

ll get(int p) {
    return fl?N-1-p:p;
}

void reset() {

    F0R(i, K) F0R(j, K) ans[i][j] = 0;

    F0R(i, N+1) pos[i].clear();
    F0R(i, N) {
        lst[i] = -1; nxt[i] = N;
    }
}

void removeFromAns(int p) {
    int B = p / K;
    F0Rd(i, B+1) {
        if (lst[p] >= i*K) break;
        ans[i][B] -= get(p);
    }
}

void addToAns(int p) {
    int B = p / K;
    F0Rd(i, B+1) {
        if (lst[p] >= i*K) break;
        ans[i][B] += get(p);
    }
}

void remove(int v, int p) {
    removeFromAns(p);
    pos[v].erase(p);
    auto it1 = pos[v].lb(p);
    auto it2 = pos[v].lb(p);
    if (it1 == pos[v].begin()) {
        if (it2 != pos[v].end()) {
            removeFromAns(*it2);
            lst[*it2] = -1;
            addToAns(*it2);
        }
    } else {
        it1--;
        if (it2 != pos[v].end()) {
            removeFromAns(*it2);
            lst[*it2] = *it1;
            nxt[*it1] = *it2;
            addToAns(*it2);
        } else {
            nxt[*it1] = N;
        }
    }
}

void add(int v, int p) {
    auto it1 = pos[v].lb(p);
    auto it2 = pos[v].lb(p);
    if (it1 == pos[v].begin()) {
        if (it2 != pos[v].end()) {
            removeFromAns(*it2);
            lst[*it2] = p; 
            nxt[p] = *it2;
            lst[p] = -1;
            addToAns(*it2);
        } else {
            nxt[p] = N;
            lst[p] = -1;
        }
    } else {
        it1--;
        if (it2 != pos[v].end()) {
            removeFromAns(*it2);
            lst[*it2] = p;
            nxt[*it1] = p;
            nxt[p] = *it2;
            lst[p] = *it1;
            addToAns(*it2);
        } else {
            nxt[*it1] = p;
            lst[p] = *it1;
            nxt[p] = N;
        }
    }

    pos[v].ins(p);

    addToAns(p);

}

ll query(ll L, ll R) {
    int b1 = (L+K-1)/K;
    int b2 = (R+1)/K - 1;

    if (b1 > b2) {
        ll res = 0;
        FOR(i, L, R+1) {
            dbg(i, lst[i]);
            if (lst[i] < L) {
                res += get(i);
            }
        }
        dbg(res);
        return res;
    }
    ll res = 0;
    FOR(i, b1, b2+1) {
        res += ans[b1][i];
    }
    dbg(res, b1, b2);
    //res stores query from b1*K to b2*K+K-1
    FOR(i, b2*K+K, R+1) {
        if (lst[i] < b1*K) {
            res += get(i);
        }
    }
    dbg(res);
    //res stores query from b1*K to R
    FOR(i, L, b1*K) {
        res += get(i);
        if (nxt[i] <= R) {
            res -= get(nxt[i]);
        }
    }

    return res;
}

vl go(vl &A, vector<pair<int, pl>> &Qs) {
    reset();

    ll cur[N]; F0R(i, N) cur[i] = A[i];
    F0R(i, N) {
        add(A[i], i);
    }

    vl res;
    trav(q, Qs) {
        if (q.f == 1) {
            remove(cur[q.s.f], q.s.f);
            cur[q.s.f] = q.s.s;
            add(cur[q.s.f], q.s.f);
        } else {
            res.pb(query(q.s.f, q.s.s));
        }
    }
    return res;
}

void solve() {
    cin >> N >> Q;
    vl A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    vector<pair<int, pl>> Qs(Q);
    F0R(i, Q) cin >> Qs[i].f >> Qs[i].s.f >> Qs[i].s.s;
    F0R(i, Q) {
        Qs[i].s.f--;
        if (Qs[i].f == 2) Qs[i].s.s--;
    }

    fl = false;
    vl A1 = go(A, Qs);

    fl = true;
    reverse(all(A));
    F0R(i, Q) {
        if (Qs[i].f == 1) {
            Qs[i].s.f = N-1-Qs[i].s.f;
        } else {
            int L = N-1-Qs[i].s.s, R = N-1-Qs[i].s.f;
            Qs[i].s.f = L; Qs[i].s.s = R;
        }
    }
    vl A2 = go(A, Qs);

    F0R(i, sz(A1)) {
        cout << A2[i] - A1[i] << nl;
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}