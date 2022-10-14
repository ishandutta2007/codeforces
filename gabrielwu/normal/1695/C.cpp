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

	int t; cin >> t;
	forn(ti, t) {
		int n, m; cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));
		forn(i, n) {
			forn(j, m) {
				cin >> v[i][j];
			}
		}

		if((n+m-1)%2 == 1) {
			cout << "NO\n";
			continue;
		}

		vector<vector<int>> dp1(n, vector<int>(m));
		vector<vector<int>> dp2(n, vector<int>(m));

		forn(i, n) {
			forn(j, m) {
				if(i == 0 && j == 0) {
					dp1[i][j] = v[i][j];
					dp2[i][j] = v[i][j];
				} else if(i == 0 || j == 0) {
					if(i == 0) {
						dp1[i][j] = v[i][j] + dp1[i][j-1];
						dp2[i][j] = v[i][j] + dp2[i][j-1];
					} else {
						dp1[i][j] = v[i][j] + dp1[i-1][j];
						dp2[i][j] = v[i][j] + dp2[i-1][j];

					}
				} else {
					dp1[i][j] = v[i][j] + min(dp1[i][j-1], dp1[i-1][j]);
					dp2[i][j] = v[i][j] + max(dp2[i][j-1], dp2[i-1][j]);
				}
			}
		}

		if(dp1[n-1][m-1] <= 0 && dp2[n-1][m-1] >= 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}