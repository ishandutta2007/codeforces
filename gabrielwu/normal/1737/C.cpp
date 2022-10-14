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
		int r1, c1, r2, c2, r3, c3;
		cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
		int o1 = (r1+c1)%2;
		int o2 = (r2+c2)%2;
		int o3 = (r3+c3)%2;

		if(o2 != o1 && o2 != o3) {
			swap(r1, r2);
			swap(c1, c2);
			swap(o1, o2);
		} else if(o2 != o3 && o1 != o3) {
			swap(r1, r3);
			swap(c1, c3);
			swap(o1, o3);
		}

		int x, y; cin >> x >> y;

		if(r1 == 1 && c1 == 1) {
			if(x == 1 || y == 1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			
		} else if(r1 == 1 && c1 == n) {
			if(x == 1 || y == n) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

		} else if(r1 == n && c1 == 1) {
			if(x == n || y == 1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

		} else if(r1 == n && c1 == n) {
			if(x == n || y == n) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

		} else {
			if((x+y)%2 != o1) {
				cout << "YES\n";
			} else {
				if(x%2 == r1%2 && y%2 == c1%2) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}

		}

	}
}