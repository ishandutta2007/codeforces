#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
#include<random>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	union_find uf(n);
	REP(i, m) {
		int k;
		cin >> k;
		int par = -1;
		REP(j, k) {
			int p;
			cin >> p;
			p--;
			if(j == 0) par = p;
			else uf.unite(par, p);
		}
	}
	vector<int> ans;
	REP(i, n) {
		ans.pb(uf.size(i));
	}
	DUMP(ans);
	return 0;
}
/* --------------------------------------- */