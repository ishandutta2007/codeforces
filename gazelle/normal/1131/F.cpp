#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
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
		mer_.resize(n);
		REP(i, n) mer_[i] = i;
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	int get_mer(int x) {
		return mer_[root(x)];
	}

	void set_mer(int x, int m) {
		mer_[root(x)] = m;
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
	std::vector<int> mer_;
};

vector<ll> ans;
vector<vector<ll>> g;

void build_ans(ll pos) {
	if(g[pos].empty()) ans.pb(pos);
	REP(i, g[pos].size()) build_ans(g[pos][i]);
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	union_find uf(n);
	uf.init(n);
	g.resize(2 * n - 1);
	REP(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		g[n + i].pb(uf.get_mer(x));
		g[n + i].pb(uf.get_mer(y));
		uf.unite(x, y);
		uf.set_mer(x, n + i);
	}
	build_ans(2 * n - 2);
	REP(i, n) ans[i]++;
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */