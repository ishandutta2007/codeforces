#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

vector<int> c[1 << 14];
bool exi[14][14];
void init(int n) {
	rep(i, (1 << n)) {
		vector<int> v;
		rep(j, n) {
			if (i&(1 << j)) {
				v.push_back(j);
			}
		}
		int len = v.size();
		rep(j, (1 << len)) {
			int s = 0;
			rep(k, len) {
				if (j&(1 << k)) {
					s += (1 << v[k]);
				}
			}
			c[i].push_back(s);
		}
	}
}

bool valid[1 << 14];
bool used[1 << 14][14];
vector<P> memo[1 << 14];
int fin;
vector<int> u; int cur;
bool dfs(int s, int id) {
	if (used[s][id])return false;
	used[s][id] = true;
	if (s == fin) {
		if (exi[u[id]][u[0]]) {
			memo[cur].push_back({ u[id] + 1,u[0] + 1 });
			return true;
		}
		else return false;
	}
	rep(j, u.size()) {
		if (s&(1 << j))continue;
		if (!exi[u[id]][u[j]])continue;
		int ns = s ^ (1 << j);
		if (dfs(ns, j)) {
			memo[cur].push_back({ u[id] + 1,u[j] + 1 });
			return true;
		}
	}
	return false;
}
bool can() {
	int sz = u.size();
	if (sz <= 2)return false;
	rep(i, (1 << sz)) {
		rep(j, sz) {
			used[i][j] = false;
		}
	}
	fin = (1 << sz) - 1;
	return dfs(1, 0);
}

bool added[1 << 14];
vector<int> G[1 << 14];
vector<int> pas, nex;
int loc;
int n;

void dfs2(int s,int id,int fr=-1) {
	if (used[s][id])return;
	used[s][id] = true;
	if (!added[s]) {
		rep(j, pas.size()) {
			if (s == (1 << id) && fr == pas[j])continue;
			if (exi[nex[id]][pas[j]]) {
				int sum = 0;
				rep(k, nex.size()) {
					if (s&(1 << k))sum += (1 << nex[k]);
				}
				G[loc].push_back(sum^loc);
				added[s] = true;
				break;
			}
		}
	}
	rep(j, nex.size()) {
		if (s&(1 << j))continue;
		if (!exi[nex[id]][nex[j]])continue;
		int ns = s ^ (1 << j);
		if (used[ns][j])continue;
		dfs2(ns, j);
	}
}
int dp[1 << 14];
int par[1 << 14];
vector<int> cv[20];

bool ans[15][15];

void search(int i) {
	loc = i;
	int xi = i ^ fin;
	pas.clear(); nex.clear();
	rep(j, n) {
		if (i&(1 << j)) {
			pas.push_back(j);
		}
		else {
			nex.push_back(j);
		}
	}
	if (pas.size() <= 2)return;
	rep(j, n) {
		if (i&(1 << j)) {
			rep(k, (1 << nex.size())) {
				added[k] = false;
				rep(l, nex.size()) {
					used[k][l] = false;
				}
			}
			rep(k, nex.size()) {
				if (!exi[j][nex[k]])continue;
				dfs2((1 << k), k, j);
			}
		}
	}
}

int fin2;
bool dfs3(int s, int id, int fr = -1) {
	if (used[s][id])return false;
	used[s][id] = true;
	if (s == fin2) {
		rep(j, pas.size()) {
			if (s == (1 << id) && fr == pas[j])continue;
			if (exi[nex[id]][pas[j]]) {
				ans[nex[id] + 1][pas[j] + 1] = true;
				return true;
			}
		}
	}
	rep(j, nex.size()) {
		if (s&(1 << j))continue;
		if (!exi[nex[id]][nex[j]])continue;
		int ns = s ^ (1 << j);
		if (used[ns][j])continue;
		if (dfs3(ns, j)) {
			ans[nex[j] + 1][nex[id] + 1] = true;
			return true;
		}
	}
	return false;
}
void add(int i, int s) {
	if (i == 0) {
		//cout << s <<" hello?"<< endl;
		rep(j, memo[s].size()) {
			int x = memo[s][j].first, y = memo[s][j].second;
			ans[x][y] = true;
		}
		return;
	}
	//cout << i << " " << s << endl;
	fin2 = 0;
	pas.clear(); nex.clear();
	rep(j, n) {
		if (i&(1 << j)) {
			pas.push_back(j);
		}
		else {
			nex.push_back(j);
		}
	}
	rep(j, nex.size()) {
		if (s&(1 << nex[j])) {
			fin2 += (1 << j);
		}
	}
	if (pas.size() <= 2)return;
	rep(j, n) {
		if (i&(1 << j)) {
			rep(k, (1 << nex.size())) {
				rep(l, nex.size()) {
					used[k][l] = false;
				}
			}
			rep(k, nex.size()) {
				if (!exi[j][nex[k]])continue;
				if (dfs3((1 << k), k, j)) {
					ans[j+1][nex[k]+1] = true;
					return;
				}
			}
		}
	}
}
void solve() {
	int m; cin >> n >> m;
	init(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		exi[a][b] = exi[b][a] = true;
	}
	rep1(i, (1 << n) - 1) {
		cur = i;
		vector<int> v;
		rep(j, n) {
			if (i&(1 << j))v.push_back(j);
		}
		u = v;
		valid[i] = can();
	}
	fin = (1 << n) - 1;
	fill(dp, dp + (1 << n), 200);
	par[0] = -1;
	dp[0] = 0;
	per1(i, (1 << n) - 1) {
		if (valid[i]) {
			cv[1].push_back(i);
			dp[i] = 1;
			par[i] = 0;
		}
	}
	fin = (1 << n) - 1;
	bool ansed = false;
	rep(l, 20) {
		rep(id, cv[l].size()) {
			int i = cv[l][id];
			if (i == fin) {
				ansed = true; break;
			}
			if (l > dp[i])continue;

			search(i);
			rep(j, G[i].size()) {
				int to = G[i][j];
				if (l + 1 < dp[to]) {
					dp[to] = l + 1;
					par[to] = i;
					if (to == fin) {
						ansed = true; break;
					}
					cv[l + 1].push_back(to);
				}
			}
		}
		if (ansed)break;
	}
	int id = fin;
	while (true) {
		int p = par[id];
		//cout << id << " "<<p<<endl;
		if (p < 0)break;
		else {
			add(p, id);
			id = p;
		}
	}
	vector<P> out;
	rep1(i, n) {
		Rep1(j, i + 1, n) {
			if (ans[i][j]||ans[j][i]) {
				out.push_back({ i,j });
			}
		}
	}
	cout << out.size() << endl;
	rep(i, out.size()) {
		cout << out[i].first << " " << out[i].second << endl;
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}