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
vector<vector<pint>> g;
int l = 0, r = 0;
void dfs(vector<int>& ans, int pos, int par, int col) {
	int tmp = 1;
	REP(i, g[pos].size()) {
		if(g[pos][i].first == par) continue;
		while(tmp == col) tmp++;
		if(tmp > r) tmp = 1;
		ans[g[pos][i].second] = tmp;
		dfs(ans, g[pos][i].first, pos, tmp);
		tmp++;
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	g.resize(n);
	REP(i, n - 1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb({y, i});
		g[y].pb({x, i});
	}
	r = n;
	while(r - l > 1) {
		int m = (l + r) / 2;
		int c = 0;
		REP(i, n) {
			if((int)g[i].size() > m) c++;
		}
		if(c <= k) r = m;
		else l = m;
	}
	cout << r << endl;
	vector<int> ans(n - 1);
	dfs(ans, 0, -1, 0);
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */