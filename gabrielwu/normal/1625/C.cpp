#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	ll n, l, k;
	cin >> n>> l >> k;
	k = n - k;

	vector<ll> d(n), v(n);
	forn(i, n) cin >> d[i];
	forn(i, n) cin >> v[i];
	d.pb(l);

	vector<vector<ll>> dp(n+1, vector<ll>(n+1, LLONG_MAX/3));

	forn(i, n+1) {
		forn(j, n) {
			if(i == 0){
				dp[i][j] = 0;
				continue;
			}
			if(j == 0) {
				dp[i][j] = d[i] * v[0];
				continue;
			}
			for(int b=1; b<i; b++) {
				ckmin(dp[i][j], dp[b][j-1] + (d[i] - d[b]) * v[b]);
			}
		}
	}

	// cout << dp << "\n";

	ll ans = LLONG_MAX;
	for(int i = k-1; i < n; i++) {
		ckmin(ans, dp[n][i]);
	}

	cout << ans << "\n";
}