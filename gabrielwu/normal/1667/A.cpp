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

	int n;
	cin >> n;
	vector<ll> v(n);
	forn(i, n) cin >> v[i];

	ll ans = LLONG_MAX;
	forn(i, n) {
		ll tot = 0;
		ll curr = 0;
		for(int j=i-1; j>=0; j--) {
			ll x = curr/v[j] + 1;
			tot += x;
			curr = x*v[j];
		}
		curr = 0;
		for(int j=i+1; j<n; j++) {
			ll x = curr/v[j] + 1;
			tot += x;
			curr = x*v[j];
		}

		ckmin(ans, tot);
	}

	// pair<ll, int> p = mp(-1, -1);
	// forn(i, n) {
	// 	ckmax(p, mp(v[i], i));
	// }

	// for(int use = -n-5; use <= n+5; use++) {
	// 	ll tot = abs(use);
	// 	ll curr = use * p.f;
	// 	for(int i = p.s - 1; i>=0; i--) {
	// 		ll x = (curr - 1)/v[i];
	// 		if(x*v[i] >= curr) {
	// 			x--;
	// 		}
	// 		assert(x*v[i] < curr);
	// 		tot += abs(x);
	// 		curr = x*v[i];
	// 	}
	// 	curr = use * p.f;
	// 	for(int i = p.s + 1; i<n; i++) {
	// 		ll x = curr/v[i] + 1;
	// 		if((x-1)*v[i] > curr) {
	// 			x--;
	// 		}
	// 		tot += abs(x);
	// 		assert(x*v[i] > curr);
	// 		curr = x*v[i];
	// 	}

	// 	ckmin(ans, tot);
	// }

	cout << ans << "\n";
}