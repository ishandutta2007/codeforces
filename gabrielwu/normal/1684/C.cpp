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

	int t;
	cin >> t;
	forn(ti, t){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));
		forn(i, n){ 
			forn(j, m) {
				cin >> v[i][j];
			}
		}

		pii ans = mp(-1, -1);
		bool works = true;
		forn(i, n) {
			vector<int> want = v[i];
			sort(want.begin(), want.end());
			vector<int> inv;
			for(int j=0; j<m; j++) {
				if(v[i][j] != want[j]) {
					inv.pb(j);
				}
			}

			if(inv.size() > 2) {
				works = false;
			} else if(inv.size() == 2) {
				ans = mp(inv[0], inv[1]);
			}
		}

		if(!works) {
			cout << -1 << "\n";
			continue;
		}
		if(ans == mp(-1, -1)) {
			cout << 1 << " " << 1 << "\n";
			continue;
		}

		forn(i, n) {
			swap(v[i][ans.f], v[i][ans.s]);
			forn(j, m-1) {
				works &= v[i][j] <= v[i][j+1];
			}
		}

		if(works) {
			cout << ans.f +1 << " " << ans.s+1 << "\n";
		} else {
			cout << -1 << "\n";
		}


	}
}