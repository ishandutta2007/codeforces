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
		int n; cin >> n;
		int o = 0, e = 0;
		forn(i, n) {
			int x; cin >> x;
			if(x%2 == 0) e++;
			else o++;
		}

		vector<vector<bool>> fe(e+1, vector<bool>(o+1));
		vector<vector<bool>> fo(e+1, vector<bool>(o+1));
		forn(i, e+1) {
			forn(j, o+1) {
				if(j == 0) {
					fe[i][j] = true;
					fo[i][j] = false; continue;
				}
				if(i == 0) {
					fe[i][j] = ((j+1)/2)%2 == 0;
					fo[i][j] = ((j+1)/2)%2 == 1;
					continue;
				}
				if(j == 1) {
					fe[i][j] = (i+j)%2 == 0;
					fo[i][j] = true;
					continue;
				}
				if(i == 1) {
					if((i+j)%2 == 0) {
						fe[i][j] = true;
						fo[i][j] = true;
					} else {
						if((j/2)%2 == 0) {
							fe[i][j] = true;
							fo[i][j] = false;
						} else {
							fe[i][j] = false;
							fo[i][j] = true;
						}
					}
					continue;
				}
				fe[i][j] = max(min(fe[i-2][j], fe[i-1][j-1]), min(fo[i-1][j-1], fo[i][j-2]));
				fo[i][j] = max(min(fo[i-2][j], fo[i-1][j-1]), min(fe[i-1][j-1], fe[i][j-2]));
			}
		}

		if(fe[e][o] == true) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
}