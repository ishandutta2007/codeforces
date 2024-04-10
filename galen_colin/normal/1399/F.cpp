#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

pll seg[3005];
int dp[6005][6005];
vi rig[6005];

// this probably doesn't work, but I don't have better ideas
// dp(l, r) = max segs on interval(l, r)
// transition: take seg(l, r) -> dp(0, l) + dp(l, r) + 1, or don't -> dp(0, r - 1)
// maybe, at each step, set dp(l, r) to max(dp(l, r), dp(l + 1, r)) and dp(l, r) to max(dp(l, r), dp(l, r - 1)) where it's interesting
// also compress coordinates

bool cmp(pll a, pll b) {
	return a.s < b.s;
}

void solve(int tc) {
	cin >> n;
	ai(seg, n);
	sort(seg, seg + n, cmp);
	
	// coordinate compression
	pair<ll, pll> compress[2 * n];
	f0r(i, n) {
		compress[2 * i] = mp(seg[i].f, mp(i, 0));
		compress[2 * i + 1] = mp(seg[i].s, mp(i, 1));
	}
	sort(compress, compress + (2 * n));
	
	ll ct = 0;
	f0r(i, 2 * n) {
		if (i > 0 && compress[i].f != compress[i - 1].f) ++ct;
		if (compress[i].s.s == 0) seg[compress[i].s.f].f = ct;
		else seg[compress[i].s.f].s = ct;
	}
	++ct;
	
	f0r(i, ct) f0r(j, ct) dp[i][j] = 0;
	
	f0r(i, ct) rig[i].clear();
	f0r(i, n) rig[seg[i].s].pb(seg[i].f);
	f0r(i, ct) sort(rig[i].rbegin(), rig[i].rend());
	
	// misread, nice
	// still shouldn't change too much
	f0r(i, ct) {
		f0r(j, i) {
			dp[j][i] = max(dp[j][i], dp[j][i - 1]);
		}
		
		for (int x: rig[i]) { // assume you take this segment
			++dp[x][i];
			int val = dp[x][i];
			if (x > 0) val += dp[0][x - 1];
			dp[0][i] = max(dp[0][i], val);
			f0rd(j, x) {
				dp[j][i] = max(dp[j][i], dp[j + 1][i]);
				dp[j][i] = max(dp[j][i], dp[j][x - 1] + dp[x][i]);
			}
		}
	}
	
	// ao(seg, n);
	
	int ans = 0;
	f0r(i, ct) {
		f0r(j, ct) {
			if (i <= j) {
				ans = max(ans, dp[i][j]);
				// cout << i << " " << j << " " << dp[i][j] << '\n';
			}
		}
	}
	cout << ans << '\n';
	
	// scared
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help

	// usaco("cowland");

	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}