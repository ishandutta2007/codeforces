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
		int n, m;
		cin >> n >> m;
		vector<ll> a(n), b(n);
		forn(i, n) cin >> a[i];
		forn(i, n) cin >> b[i];
		vector<ll> pref(n+1);

		forn(i, n) {
			pref[i+1] = a[i] - b[i] + pref[i];
		}
		vector<vector<int>> release(n+1);
		vector<int> stuck(m);
		vector<pii> ints(m);
		forn(i, m) {
			int x, y;
			cin >> x >> y;
			x--;
			ints[i] = {x, y};
			stuck[i] = (pref[y] != 0) + (pref[x] != 0);
			if(pref[y] != 0) release[y].pb(i);
			if(pref[x] != 0) release[x].pb(i);
		}

		vector<int> stack;
		set<int> alive;
		forn(i, n+1) {
			if(pref[i] != 0) alive.insert(i);
		}
		forn(i, m) {
			if(stuck[i] == 0) stack.pb(i);
		}


		while(stack.size()){
			int x = stack.back(); stack.pop_back();
			assert(pref[ints[x].f] == 0 && pref[ints[x].s] == 0);

			auto it = alive.lower_bound(ints[x].f);
			while(it != alive.end() && (*it) < ints[x].s) {
				pref[*it] = 0;
				for(int oth: release[*it]) {
					stuck[oth]--;
					if(stuck[oth] == 0) {
						stack.pb(oth);
					}
				}
				auto curr = it;
				it++;
				alive.erase(curr);
			}
		}

		if(alive.size() == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}
}