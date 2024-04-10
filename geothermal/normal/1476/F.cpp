#include <bits/stdc++.h>
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
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr <<  endl;


const int MOD = 998244353;
const char nl = '\n';
const int MX = 1001; 

const int BAD = -500001;


ll SZ = 262144*2; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return max(a, b); }


void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = BAD, resR = BAD; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}


void solve() {
    int N; cin >> N;
    int A[N+1]; FOR(i, 1, N+1) cin >> A[i];
    A[0] = 0;
    int dp[N+1], lst[N+1];
    F0R(i, N+1) {
        dp[i] = BAD;
        lst[i] = 0;
    }
	dp[0] = 0;
    vpi ev;
    int lp[N+1];
    F0R(i, N+1) lp[i] = -1;
    FOR(i, 1, N+1) {
        ev.pb({i - A[i] - 1, i});
    }
    
	sort(all(ev));
    int p = 0, seqPos = 0, cap = 0;
    while (p < N && ev[p].f <= 0) {
        lp[ev[p].s] = 0;
        p++;
    }
    int hip = 0;
    FOR(i, 1, N+1) {
        if (dp[hip] >= i - A[i] - 1) {
            dp[i] = max(i-1, dp[hip]);
            lst[i] = hip;
        }
        if (lp[i] != -1) {
            if(ckmax(dp[i], (int) query(lp[i]+1, i-1))) {
                lst[i] = lp[i];
            }
        }
        update(i, i+A[i]);
        if (dp[i] > dp[hip]) {
            hip = i;
        }
        if (dp[i] > cap) {
            seqPos = i;
            cap = dp[i];
            int x = i+1;
            while (x <= cap && x <= N) {
                ckmax(cap, x+A[x]);
                x++;
            }
        }
        while (p < N && ev[p].f <= cap) {
            lp[ev[p].s] = seqPos;
            p++;
        }
    }
  
    if (dp[N] < N) {
        cout << "NO" << nl; return;
    }
    cout << "YES" << nl;
    bool left[N+1]; F0R(i, N+1) left[i] = false;
    int cur = N;
    while (cur > 0) {
        left[cur] = true;
        cur = lst[cur];
    }
    
    FOR(i, 1, N+1) {
        cout << (left[i]?'L':'R');
    }
    cout << nl;
    

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}