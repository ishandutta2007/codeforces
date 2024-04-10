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
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n;
ll a[1 << 18];
vector<int> G[1 << 18];

int p[1 << 18];
vector<int> g[1 << 18];
bool used[1 << 18];
LP dp[1 << 18];
LP dfs(int id) {
	used[id] = true;
	LP res = { a[id],0 };
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to])p[id] = to;
		else {
			g[id].push_back(to);
			LP nex = dfs(to);
			res.first += nex.first;
			res.second += nex.first + nex.second;
		}
	}
	return dp[id] = res;
}
ll out = 0;
void ans(int id) {
	if (id > 0) {
		int par = p[id];
		dp[id] = { dp[par].first,dp[par].first - dp[id].first + dp[par].second - dp[id].first  };
	}
	out = max(out, dp[id].second);
	//cout << id << " " << dp[id].first<<" "<<dp[id].second << endl;
	rep(j, g[id].size()) {
	    ans(g[id][j]);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0); ans(0); cout << out << endl;
	return 0;
}