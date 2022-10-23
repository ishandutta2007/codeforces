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
const int MX = 100001; 

ll SZ = 262144; //set this to power of two
pl* seg = new pl[2*SZ]; //segtree implementation by bqi343's Github

pl combine(pl a, pl b) { return {a.f+b.f, a.s+b.s}; }

void update(int p, ll value, ll val2) {  
    p += SZ;
    seg[p].f += value;
    seg[p].s += val2;
    for (; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

pl query(int l, int r) {  // sum on interval [l, r]
    pl resL = {0, 0}, resR = {0, 0}; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}


void solve() {
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    int b1 = 0, b2 = 0;
    ll firstBad[N], secBad[N];
    F0R(i, N) {
        firstBad[i] = N;
        secBad[i] = N;
    }

    F0R(i, N) {
        int cur = b1;
        while (i - A[i] + 1 > b1) {
            firstBad[b1] = i;
            b1++;
        }
        while (b2 < cur && i - A[i] + 1 > b2) {
            secBad[b2] = i;
            b2++;
        }
    }

    ll ans = 0;
    F0R(i, N) {
        ans += firstBad[i] - i;
    }

    vpl vals[N];
    F0R(i, N) {
        if (firstBad[i] < N) vals[firstBad[i]].pb({i, secBad[i]-firstBad[i]});
    }
    F0R(i, N) {
        vals[i].pb({-MOD, 0});
        sort(all(vals[i]));
        F0R(j, sz(vals[i]) - 1) {
            vals[i][j+1].s += vals[i][j].s;
        }
    }

    int Q; cin >> Q;
    vector<pair<pi, int>> q(Q);
    F0R(i, Q) {
        cin >> q[i].f.f >> q[i].f.s;
        q[i].f.f--;
        q[i].s = i;
    }
    sort(all(q));
    ll res[Q];
    int p = -1;
    trav(a, q) {
        //dbg(a);
        while (p < a.f.f) {
            p++;
            update(p, firstBad[p], 1);
            trav(b, vals[p]) {
                if (b.f < 0) continue;
                update(b.f, -firstBad[b.f], -1);
            }
        }

        res[a.s] = ans;
        //dbg(a.s, ans);
        pl qq = query(0, min(a.f.f-a.f.s, (int) SZ-1));
        res[a.s] -= qq.f;
        res[a.s] += qq.s * a.f.f;
        //dbg(a.s, res[a.s]);
        //dbg(qq);

        auto it = lb(all(vals[a.f.f]), mp((ll) a.f.f-a.f.s+1, (ll) -1));
        it--;
        res[a.s] += vals[a.f.f][sz(vals[a.f.f])-1].s - it->s;
        //dbg(a.s, res[a.s]);

    }
    //dbg(vals[2]);

    F0R(i, Q) {
        cout << res[i] << nl;
    }



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}