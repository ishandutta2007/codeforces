#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

class union_find {
public:
	union_find(int n)
	: par_(n, -1)
	{}
	void init(int n) {
		par_.assign(n, -1);
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if(x == y) {
			return false;
		} else {
			if(par_[x] < par_[y]) {
				par_[x] += par_[y];
				par_[y] = x;
			} else {
				par_[y] += par_[x];
				par_[x] = y;
			}
			return true;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return -par_[root(x)];
	}

private:
	std::vector<int> par_;
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m, d;
	cin >> n >> m >> d;
	vector<vector<ll>> g(n);
	vector<pll> edg(m);
	REP(i, m) {
		cin >> edg[i].first >> edg[i].second;
		edg[i].first--;
		edg[i].second--;
		g[edg[i].first].pb(edg[i].second);
		g[edg[i].second].pb(edg[i].first);
	}

	union_find uf(n), uf2(n);
	vector<pll> ans;
	set<pll> s;
	REP(i, m) {
		if(edg[i].first == 0 || edg[i].second == 0) continue;
		uf.unite(edg[i].first, edg[i].second);
	}
	int c = 0;
	REP(i, g[0].size()) {
		if(!uf.same(0, g[0][i])) {
			uf.unite(0, g[0][i]);
			uf2.unite(0, g[0][i]);
			c++;
			ans.pb(pll(1, g[0][i] + 1));
			s.insert(pll(0, g[0][i]));
		}
	}
	if(c <= d && (ll)g[0].size() >= d) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
		return 0;
	}
	ll pos = 0;
	while(c < d) {
		if(!s.count(pll(0, g[0][pos]))) {
			c++;
			ans.pb(pll(1, g[0][pos] + 1));
			uf2.unite(0, g[0][pos]);
		}
		pos++;
	}
	REP(i, m) {
		if(edg[i].first == 0 || edg[i].second == 0) continue;
		if(!uf2.same(edg[i].first, edg[i].second)) {
			uf2.unite(edg[i].first, edg[i].second);
			ans.pb({edg[i].first + 1, edg[i].second + 1});
		}
	}
	REP(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
/* --------------------------------------- */