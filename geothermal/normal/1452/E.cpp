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
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void solve() {
	int N, M, K; cin >> N >> M >> K;
	int L[M], R[M];
	F0R(i, M) {
		cin >> L[i] >> R[i];
		L[i]--; R[i]--;
	}
	int ans = 0;
	F0R(i, N-K+1) {
		int pre1[N+1], pre2[N+1];
		F0R(j, N+1) {
			pre1[j] = 0; pre2[j] = 0;
		}
		int sum = 0;
		
		F0R(j, M) {
			int cur = max(0, min(i+K-1, R[j]) - max(i, L[j]) + 1);
			
			sum += cur;
			if (cur == R[j]-L[j]+1 || cur == K) continue;
			cur++;
			int lo = L[j]+cur-K;
			ckmax(lo, 0);
			int hi = R[j] - cur + 1;
			ckmin(hi, N-K);
			if (lo > hi) continue;
			if (i == 0) {
				dbg(j, lo, hi);
			}
			//dbg(i, j, lo, hi);

			//case 1: segment is small

			//lo .. L-1
			//L .. R - K
			//R - K + 1 .. hi
			if (true) {
				int X = min(L[j] - 1, R[j] - K);
				if (lo <= X) {
					pre2[lo]++; pre2[X+1]--;
					int over = max(0, min(lo+K-1, R[j]) - max(lo, L[j]) + 1);
					
					pre1[lo] += over - lo - (cur-1);
					pre1[X+1] -= over - lo - (cur-1);
				}
			}
			if (true) {
				int X = min(L[j], R[j] - K + 1);
				int Y = max(L[j] - 1, R[j] - K);
				ckmin(Y, hi);
				ckmax(X, lo);
				if (X <= Y) {
					int over = max(0, min(X+K-1, R[j]) - max(X, L[j]) + 1);
					
					pre1[X] += over - (cur-1);
					pre1[Y+1] -= over - (cur-1);
				}
			}
			if (true) {
				int X = max(L[j], R[j]-K+1);
				if (X <= hi) {	
					pre2[X]--; pre2[hi+1]++;
					int over = max(0, min(X+K-1, R[j]) - max(L[j], X) + 1);
					
					pre1[X] += over + X - (cur-1);
					pre1[hi+1] -= over + X - (cur-1);
				}

			}
			
			
		}
		int c1 = 0, c2 = 0;
		ckmax(ans, sum);
		F0R(j, N-K+1) {
			c1 += pre1[j], c2 += pre2[j];
			//dbg(i, j, c1, c2);
			if (sum + c1 + c2 * j == 19) {
				dbg(i, j, sum, c1, c2);
			}
			ckmax(ans, sum + c1 + c2 * j);
		}
	}
	cout << ans << nl;

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