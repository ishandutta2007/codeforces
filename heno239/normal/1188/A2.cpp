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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int n;
struct edge {
	int to, cost;
};
vector<edge> G[1000];
vector<P> nd[1000];

vector<pair<P, int>> ans;

int root;

void dfs(int id, int fr, int obc) {
	vector<vector<P>> v;
	int sum = 0;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (fr == to)continue;
		dfs(to, id, G[id][j].cost);
		v.push_back(nd[to]);
	}
	if (G[id].size() == 2) {
		if (fr == root) {
			rep(i, v.size()) {
				rep(j, v[i].size()) {
					ans.push_back({ { root,v[i][j].first },v[i][j].second });
				}
			}
		}
		else {
			rep(i, v.size()) {
				rep(j, v[i].size()) {
					nd[id].push_back(v[i][j]);
				}
			}
		}
		return;
	}
	if (G[id].size() == 1 && fr >= 0) {
		nd[id].push_back({ id,obc });
		return;
	}
	if (fr < 0)return;
	//cout << "hello" << endl;
	//cout << id << " " << v.size() << endl;
	rep(i, v.size()) {
		rep(j, v[i].size()) {
			sum += v[i][j].second;
		}
	}
	int dif = obc - sum;
	dif = -dif / 2;
	ans.push_back({ { v[0][0].first,v[1][0].first } ,dif });
	v[0][0].second -= dif; v[1][0].second -= dif;
	if (fr == root) {
		rep(i, v.size()) {
			rep(j, v[i].size()) {
				ans.push_back({ { root,v[i][j].first },v[i][j].second });
			}
		}
	}
	else {
		rep(i, v.size()) {
			rep(j, v[i].size()) {
				nd[id].push_back(v[i][j]);
			}
		}
	}
}

void solve() {
	cin >> n;
	rep(i, n - 1) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	if (n == 2) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << "1 2 " << G[0][0].cost << endl;
		return;
	}
	rep(i, n) {
		if (G[i].size() == 2) {
			if (G[i][0].cost != G[i][1].cost) {
				cout << "NO" << endl; return;
			}
		}
	}
	rep(i, n)if (G[i].size() == 1) {
		root = i; break;
	}
	//cout << root << endl;
	dfs(root, -1, 0);
	cout << "YES" << endl;
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		int u = ans[i].first.first;
		int v = ans[i].first.second;
		int c = ans[i].second;
		cout << u + 1 << " " << v + 1 << " " << c << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}