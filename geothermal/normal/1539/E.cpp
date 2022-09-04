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

pi merge(pi A, pi B) {
    if (A.f == -1) return {-1, -1};
    if (B.f == -1) return {-1, -1};
    pi res = {max(A.f, B.f), min(A.s, B.s)};
    if (res.f > res.s) return {-1, -1};
    return res;
}

bool valid(pi A, int B) {
    return A.f <= B && B <= A.s;
}

pi inter[MX+1][18][2];
int N, M;

int lastValid(int v, int p, int x) {
    pi range = {0, M};
    F0Rd(i, 18) {
        while (valid(merge(range, inter[p][i][x]), v)) {
            range = merge(range, inter[p][i][x]);
            p += 1 << i;
            ckmin(p, N);
        }
    }
    return p;
}

void solve() {

    cin >> N >> M;
    int K[N];
    pi val[N][2];
    F0R(i, N) {
        cin >> K[i] >> val[i][0].f >> val[i][0].s >> val[i][1].f >> val[i][1].s;
    }

    F0R(x, 2) {
        F0R(i, 18) inter[N][i][x] = {-1, -1};
        F0Rd(i, N) {
            inter[i][0][x] = val[i][x];
            FOR(j, 1, 18) {
                inter[i][j][x] = merge(inter[i][j-1][x], inter[min(i+(1 << (j-1)), N)][j-1][x]);
            }
        }
    }

    int dp[N][2]; F0R(i, N) F0R(j, 2) dp[i][j] = -1;
    int lst[N][2]; 

    if (valid(val[0][0], K[0])) {
        dp[0][0] = lastValid(0, 0, 1);
    }
    if (valid(val[0][1], K[0])) {
        dp[0][1] = lastValid(0, 0, 0);
    }

    FOR(i, 1, N) {
        if (dp[i-1][0] >= i) {
            if (valid(val[i][0], K[i]) && ckmax(dp[i][0], dp[i-1][0])) {
                lst[i][0] = 0;
            }
            if (valid(val[i][1], K[i]) && ckmax(dp[i][1], lastValid(K[i-1], i, 0))) {
                lst[i][1] = 0;
            }
        } 
        if (dp[i-1][1] >= i) {
            if (valid(val[i][1], K[i]) && ckmax(dp[i][1], dp[i-1][1])) {
                lst[i][1] = 1;
            }
            if (valid(val[i][0], K[i]) && ckmax(dp[i][0], lastValid(K[i-1], i, 1))) {
                lst[i][0] = 1;
            }

        }
    }

    int p = 0;
    if (dp[N-1][1] > dp[N-1][0]) p = 1;
    if (dp[N-1][p] == N) {
        cout << "Yes" << nl;
        vi res;
        res.pb(p);
        FORd(i, 1, N) {
            p = lst[i][p];
            res.pb(p);
        }
        reverse(all(res));
        trav(a, res) cout << a << " ";
        cout << nl;
    } else {
        cout << "No" << nl;
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