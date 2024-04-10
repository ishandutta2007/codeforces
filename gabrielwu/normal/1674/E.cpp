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
	vector<int> v(n);
	forn(i, n) cin >> v[i];

	ll ans = MOD;
	ll small = MOD, ssmall = MOD;
	forn(i, n) {
		if(v[i] < small) {
			ssmall = small;
			small = v[i];
		} else if(v[i] < ssmall) {
			ssmall = v[i];
		}
	}

	ckmin(ans, (small+1) / 2 + (ssmall+1) / 2);
	forn(i, n-1) {
		ll x = v[i], y = v[i+1];
		if(x < y) swap(x, y);
		if(x+1 >= y * 2) {
			ckmin(ans, (x+1)/2);
		} else {
			ll curr = x-y;
			x -= 2*curr;
			y -= curr;
			assert(x >= 0);
			assert(y >= 0);
			if(x%3 == 0) {
				curr += 2*x/3;
			} else if(x%3 == 1) {
				curr += 2*(x/3) + 1;
			} else {
				curr += 2*(x/3) + 2;
			}
			ckmin(ans, curr);
		}
	}

	forn(i, n-2) {
		ckmin(ans, (ll) (v[i] + v[i+2] + 1)/2);
		ckmin(ans, (ll) max(v[i], v[i+2]));
	}

	cout << ans << "\n";
}