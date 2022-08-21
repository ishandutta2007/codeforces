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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n, m;
vector<int> G[1 << 19];
ll sum = 0;
vector<LP> query[1 << 19];
bool used[1 << 19];
ll hd[1 << 19];
ll ans[1 << 19];
void dfs(int id, int hei) {
	used[id] = true; 
	rep(i, query[id].size()) {
		ll nh = query[id][i].first + hei + 1;
		nh = min(nh, (ll)n + 1);
		hd[nh] += query[id][i].second;
		sum += query[id][i].second;
	}
	sum -= hd[hei];
	ans[id] = sum;
	rep(i, (int)G[id].size()) {
		int to = G[id][i];
		if (used[to])continue;
		dfs(to, hei + 1);
	}
	sum += hd[hei];
	rep(i, query[id].size()) {
		ll nh = query[id][i].first + hei + 1;
		nh = min(nh, (ll)n + 1);
		hd[nh] -= query[id][i].second;
		sum -= query[id][i].second;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> m;
	rep(i, m) {
		int v; ll d, x; cin >> v >> d >> x; v--;
		query[v].push_back({ d,x });
	}
	dfs(0,0);
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}