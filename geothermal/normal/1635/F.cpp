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
const int MX = 200001; 


ll SZ = 262144*2; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return min(a, b); }


void update(int p, ll value) {  
    for (ckmin(seg[p += SZ], value); p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 8e18, resR = 8e18; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
void solve() {
    int N, Q; cin >> N >> Q;
    vector<pair<pi, ll>> vals[2];
    vl X(N), W(N); F0R(i, N) cin >> X[i] >> W[i];
    F0R(ir, 2) {
        set<pi> pos;
        int lst[N];
        lst[0] = -1;
        pos.ins({W[0], 0});

        FOR(i, 1, N) {

            auto it = pos.lb({W[i], -1});
            if (it == pos.begin()) {
                lst[i] = -1;
            } else {
                it--;
                lst[i] = it->s;
            }

            int p = i-1;
            while (W[p] >= W[i]) {
                vals[ir].pb({{p, i}, abs(X[i]-X[p])*(W[i]+W[p])});
                if (lst[p] == -1) break;
                p = lst[p];
            }

            while (sz(pos) && pos.rbegin()->f > W[i]) {
                pos.erase(*pos.rbegin());
            }
            pos.ins({W[i], i});
        }
        reverse(all(X)); reverse(all(W));
    }

    vector<pair<pi, ll>> ops;
    trav(a, vals[0]) {
        ops.pb({{a.f.s, a.f.f}, a.s});
    }
    trav(a, vals[1]) {
        ops.pb({{N-1-a.f.f, N-1-a.f.s}, a.s});
    }
    sort(all(ops));
    //dbg(ops);
    F0R(i, 2*SZ) {
        seg[i] = 8e18;
    }

    vector<pair<pi, int>> qs(Q);

    F0R(i, Q) {
        cin >> qs[i].f.s >> qs[i].f.f;
        qs[i].f.s--; qs[i].f.f--;
        qs[i].s = i;

    }
    sort(all(qs));
    ll ans[Q];
    int p = 0;
    trav(a, qs) {
        while (p < sz(ops) && ops[p].f.f <= a.f.f) {
            update(ops[p].f.s, ops[p].s);
            p++;
        }
        ans[a.s] = query(a.f.s, a.f.f);
    }
    F0R(i, Q) {
        cout << ans[i] << nl;
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