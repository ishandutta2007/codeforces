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
const ll mod = 1000000007;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n;
ll w[1 << 19];
struct edge { int to; ll cost; };
vector<edge> G[1 << 19];
bool used[1 << 19];
ll out = 0;
ll dfs(int id) {
	used[id] = true;
	ll res = w[id];
	vector<ll> v;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (used[to])continue;
		ll sum = dfs(to) - G[id][j].cost;
		if (sum >= 0)v.push_back(sum);
	}
	sort(v.begin(), v.end(), greater<ll>());
	if (v.size() == 0) {
		out = max(out, res);
	}
	else if (v.size() == 1) {
		res += v[0];
		out = max(out, res);
	}
	else {
		res += v[0];
		out = max(out, res + v[1]);
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> w[i];
	}
	rep(i, n - 1) {
		int u, v; ll c;
		cin >> u >> v >> c; u--; v--;
		G[u].push_back({ v,c });
		G[v].push_back({ u,c });
	}
	dfs(0);
	cout << out << endl;
	return 0;
}