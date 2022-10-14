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
	forn(ti, t) {
		int n;
		cin >> n;
		vector<int> v(n);
		set<int> avail;
		forn(i, n) {
			cin >> v[i];
			v[i]--;
			avail.insert(i);
		}

		if(n == 1) {
			cout << -1 << "\n";
			continue;
		}

		vector<int> ans;
		forn(i, n-2) {
			if(*avail.begin() != v[i]) {
				ans.pb(*avail.begin());
				avail.erase(avail.begin());
			} else {
				ans.pb(*(++avail.begin()));
				avail.erase(++avail.begin());
			}
		}

		assert(avail.size() == 2);
		if(v[n-1] == *(--avail.end()) || v[n-2] == *avail.begin()) {
			ans.pb(*(--avail.end()));
			ans.pb(*(avail.begin()));
		} else {
			ans.pb(*(avail.begin()));
			ans.pb(*(--avail.end()));
		}

		forn(i, n) {
			cout << ans[i]+1 << " ";
		}cout << "\n";
	}
}