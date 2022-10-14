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
		vector<int> v(n);
		set<int> s;
		unordered_map<int, int> trans;
		forn(i, n) {
			cin >> v[i];
			s.insert(v[i]);
		}

		int ind = 0;
		for(int x: s) {
			trans[x] = ind++;
		}

		vector<vector<int>> occ(ind);
		forn(i, n) {
			v[i] = trans[v[i]];
			occ[v[i]].pb(i);
		}

		vector<pii> ints(m);
		forn(i, m) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			ints[i] = mp(l, r);
		}

		sort(ints.begin(), ints.end(), [](pii a, pii b){
			if(a.f != b.f) return a.f < b.f;
			return a.s > b.s;
		});
		vector<pii> nints;
		int reach = -1;
		for(pii p: ints) {
			if(p.s <= reach) continue;
			ckmax(reach, p.s);
			nints.pb(p);
		}

		ints = nints;
		m = nints.size();

		int lo = 0;
		int hi = n;
		// cout << "HERE" << endl;
		while(lo < hi) {
			int mid = (lo + hi)/2;
			vector<int> l(ind), r(ind);

			int lbound = 0, rbound = n-1;
			pii bef = {0, 0};
			vector<pii> banned;
			for(pii p: ints) {
				assert(p.s >= bef.s);
				for(int i=bef.f; i<p.f; i++) {
					l[v[i]]++;
				}
				for(int i=bef.s; i<=p.s; i++) {
					r[v[i]]++;
				}

				for(int i=bef.s; i<=p.s; i++) {

					if(l[v[i]] == r[v[i]]) {
						assert(i < p.f);
						continue;
					}
					if(l[v[i]] + 2 == r[v[i]]) {
						int a = occ[v[i]][l[v[i]]], d = occ[v[i]][l[v[i]]+1];
						ckmin(rbound, d);
						ckmax(lbound, a - mid+1);
						if(a + mid < d) {
							banned.pb({a+1, d-mid});
						}
					} else if(l[v[i]] + 3 <= r[v[i]]) {
						int a = occ[v[i]][l[v[i]]], d = occ[v[i]][r[v[i]]-1];
						int b = occ[v[i]][l[v[i]]+1], c = occ[v[i]][r[v[i]]-2];
						ckmin(rbound, b);
						ckmax(lbound, c - mid+1);
						if(a + mid < d) {
							banned.pb({a+1, d-mid});
						}
					}
					if(lbound > rbound) break;
				}
				if(lbound > rbound) break;

				bef = {p.f, p.s+1};
			}
			bool works = true;
			if(lbound > rbound) works = false;
			else {
				bool found = false;
				sort(banned.begin(), banned.end(), [](pii a, pii b){
					if(a.f != b.f) return a.f < b.f;
					return a.s > b.s;
				});
				int reach = -1;
				for(pii p: banned) {
					if(p.s <= reach) continue;

					if(p.f > reach+1) {
						if(reach < rbound && p.f > lbound) {
							found = true;
							break;
						}
					}
					ckmax(reach, p.s);
				}
				if(reach < rbound) found = true;
				
				if(found) works = true;
				else works = false;
			}

			if(works) {
				hi = mid;
			} else {
				lo = mid+1;
			}
			// cout << "lo hi " << lo << " " << hi << endl;
		}

		cout << lo << "\n";
		// cout << endl;
	}
}