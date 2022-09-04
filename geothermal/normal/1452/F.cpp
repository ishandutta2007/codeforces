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
#ifdef DEBUG
#define dbg(x...) cerr << ""<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int N;
ll A[31];
ll B[31];
const ll INF = 1e16;

ll get(int p, ll V) { 
	if (V <= 0) return 0;
	if (p >= N) {
		return INF;
	}
	V -= A[p];
	if (V <= 0) return 0;
	// break up (V+1)/2 of next type
	B[p] += ((V+1)/2) * 2;
	B[p+1] -= (V+1)/2;
	return (V+1)/2 + get(p+1, (V+1)/2);
}

void solve() {
	int Q; cin >> N >> Q;
	F0R(i, N) cin >> A[i];
	while(Q--) {
		int T; cin >> T;
		if (T == 1) {
			int X, Y; cin >> X >> Y;
			A[X] = Y;
		} else {
			int X; ll K; cin >> X >> K;
			ll curSum = 0;
			F0R(i, 31) B[i] = A[i];
			F0R(i, X) curSum += A[i] * (1ll << i);
			ll need = K - curSum;
			ll ans = 0;
			if (need > 0) {
				need = (need + (1ll << X) - 1) / (1ll << X);
				ans = get(X, need);
				if (ans >= INF) {
					cout << -1 << nl; continue;
				}
			}
			F0R(i, N) {
				dbg(i, B[i]);
			}
			ll cc = 0;
			F0R(i, X+1) cc += B[i];
			if (cc < K) {
				FOR(i, X+1, N) {
					ll V = 1ll << (i-X);
					ll cur = min(B[i], (K-cc)/V);
					if (cc >= K) cur = 0;
					ans += cur * (V - 1);
					cc += cur * V;
				}
				ans += max(K - cc, 0ll);
			}
			cout << ans << nl;

			/*ll numLo = 0; F0R(i, X) numLo += A[i];
			ll res = get(X, K-numLo);
			if (res >= INF) {
				ll sum = 0;
				ll cnt = 0;
				ll ns = 0;
				F0R(i, N) {
					sum += (1ll << i) * A[i];
					if (i <= X) {
						cnt += A[i];
					} else { 
						cnt += A[i] * (1ll << (i-X));
						ns += A[i] * ((1ll << (i-X)) - 1);
					}
				}
				if (sum >= K) {
					cout << ns + K - cnt << nl;
				} else {
					cout << -1 << nl;
				}
			} else cout << res << nl;*/
		}
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