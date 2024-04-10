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

const int K = 20;
void solve() {
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    int nxtMiss[N][K];
    F0R(i, K) nxtMiss[N-1][i] = N;
    F0R(i, K) {
        if ((A[N-1] & (1 << i)) == 0) nxtMiss[N-1][i] = N-1;
    }
    F0Rd(i, N-1) {
        F0R(j, K) {
            nxtMiss[i][j] = nxtMiss[i+1][j];
            if ((A[i] & (1 << j)) == 0) {
                nxtMiss[i][j] = i;
            }
        }
    }

    int val[K];
    int cur = 0;
    F0Rd(i, K) {
        cur ^= 1 << i;
        val[i] = cur;
    }

    vector<vector<int>> pos[K]; 
    F0R(i, K) {
        F0R(j, (val[i] >> i) + 1) {
            pos[i].pb(vi());
        }
    }
    cur = 0;
    F0R(i, N) {
        cur ^= A[i];
        F0R(j, K) {
            pos[j][(cur&val[j])>>j].pb(i);
        }
    }
    int ans = 0;
    cur = 0;
    //dbg(pos[1][8]);
    F0R(i, N) {
        F0R(j, K) {
            int v = (cur&val[j]) >> j;
            auto it = lb(all(pos[j][v]), nxtMiss[i][j]);
            if (it != pos[j][v].begin()) {
                it--;
                int p = *it;
                /*if (p >= i) {
                    dbg(i, j, p, cur, val[j]);
                }*/
                ckmax(ans, p - i + 1);
            }
        }
        cur ^= A[i];
    }
    cout << ans << nl;

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