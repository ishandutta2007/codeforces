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

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ans = 0;
	for(ll z = c; z <= d; z++) {
		if(a + b > z) {
			ans += (b-a+1)*(c-b+1);
		} else if(z <= min(a + c, b + b)) {
			ll s = z - (a+b) + 1;
			ans += (b-a+1)*(c-b+1);
			ans -= (s*(s+1))/2;
		} else if(z < max(a+c, b+b)) {
			ll s = min(b-a+1, c-b+1);
			ans += (b-a+1)*(c-b+1);
			ans -= (s*(s+1))/2;
			ans -= min(b-a+1, c-b+1) * (z - min(a+c, b+b));
		} else if(z <= b + c) {
			ll s = b + c - z;
			ans += s*(s+1)/2;
		} else {
			ans += 0;
		}

	}
	cout << ans << "\n";
}