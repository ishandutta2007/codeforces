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

	int n; cin >> n;

	if(n == 1) {
		cout << 2 << "\n";
		return 0;
	}

	vector<vector<ll>> a(n, vector<ll>(n));
	int si, sj;
	forn(i, n) {
		forn(j, n) {
			cin >> a[i][j];
			if(a[i][j] == 0) {
				si = i;
				sj = j;
			}
		}
	}

	ll x = 0;
	forn(i, n) {
		x -= a[i][sj];
		x += a[i][(sj+1)%n];
	}

	a[si][sj] = x;
	ll spec = 0;
	forn(i, n) {
		spec += a[i][0];
	}

	forn(i, n) {
		ll t = 0;
		forn(j, n) {
			t += a[i][j];
		}
		if(t != spec) {
			cout << -1 << "\n";
			return 0;
		}
	}
	forn(i, n) {
		ll t = 0;
		forn(j, n) {
			t += a[j][i];
		}
		if(t != spec) {
			cout << -1 << "\n";
			return 0;
		}
	}
	ll t = 0;
	forn(j, n) {
		t += a[j][j];
	}
	if(t != spec) {
		cout << -1 << "\n";
		return 0;
	}
	t = 0;
	forn(j, n) {
		t += a[n-1-j][j];
	}
	if(t != spec) {
		cout << -1 << "\n";
		return 0;
	}
	if(x <= 0) {
		cout << -1 << "\n";
		return 0;
	}

	cout << x << "\n";

}