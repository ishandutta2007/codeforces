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
const int MX = 20000001; 

int get(int A, int B, int b) {
    bool X = A & (1 << b);
    bool Y = B & (1 << b);
    if (X == Y) return 1 + 2 * X;
    if (Y) return 0;
    return 2;
}

int nxt[MX][2];
int dp[MX][4];
int nxtNode = 1;

void addDP(int A, int B, int v) {
    int p = 0;
    F0Rd(i, 30) {
        int nv = nxt[p][get(A, B, i)%2];
        if (nv == -1) {
            nv = nxtNode;
            nxtNode++;
            nxt[p][get(A, B, i)%2] = nv;
        }
        /*if (B == 6) {
            cout << i << " " << get(A, B, i) << " " << p << " ADD" <<  endl;
        }*/
        ckmax(dp[p][get(A, B, i)], v);
        p = nv;
    }
}

int getBest(int A, int B) {
    int ans = 0;
    int p = 0;
    F0Rd(i, 30) {
        int cur = get(A, B, i);
        if (cur == 1) {
            ckmax(ans, dp[p][0]);
        } else if (cur == 3) {
            ckmax(ans, dp[p][2]);
        } else if (cur == 0) {
            ckmax(ans, dp[p][1]);
        } else {
            ckmax(ans, dp[p][3]);
        }
        /*if (A == 7) {
            cout << i << " " << get(A, B, i) << " " << p << " " << ans << endl;
        }*/
        cur %= 2;
        int nv = nxt[p][cur];
        if (nv == -1) {
            nv = nxtNode;
            nxtNode++;
            nxt[p][cur] = nv;
        }
        p = nv;
    }
    return ans+1;
}

void solve() {
    int N; cin >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    nxtNode = 1;
    F0R(i, N*62) {
        nxt[i][0] = -1; nxt[i][1] = -1; 
        dp[i][0] = 0; dp[i][1] = 0; dp[i][2] = 0; dp[i][3] = 0;
    }
    int res = 0;
    F0R(i, N) {
        int bst = getBest(i, A[i]);
        //dbg(bst);
        ckmax(res, bst);
        addDP(A[i], i, bst);
    }

    cout << res << nl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}