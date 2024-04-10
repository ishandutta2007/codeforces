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
		int n, q; cin >> n >> q;
		vector<int> v(n);
		forn(i, n) cin >> v[i];
		deque<int> order;
		forn(i, n) order.pb(i);

		vector<pair<pii, int>> queries(q);
		forn(qi, q) {
			int i, k; cin >> i >> k;
			queries[qi] = {{k, i}, qi};
		}

		sort(queries.begin(), queries.end());
		vector<int> ans(q);

		vector<int> wins(n);

		int curr = 0;
		int cq = 0;
		while(cq < q) {
			while(curr < queries[cq].f.f) {
				if(curr > n) {
					wins[order.front()] += queries[cq].f.f - curr;
					curr = queries[cq].f.f;
				} else {
					int a = order.front(); order.pop_front();
					int b = order.front(); order.pop_front();
					if(v[a] > v[b]) swap(a, b);
					order.push_front(b);
					order.push_back(a);
					wins[b]++;
					curr++;
				}
			}
			// cout << wins << "\n";
			assert(curr == queries[cq].f.f);
			ans[queries[cq].s] = wins[queries[cq].f.s-1];
			cq++;
		}

		forn(i, q) cout << ans[i] << "\n";
	}
}