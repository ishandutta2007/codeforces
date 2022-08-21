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
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll dp[5000][5001],cop[5001];
vector<int> G[5000];
ll c[5000], d[5000];
int x[5000];
vector<ll> v[5000];
void init() {
	rep(i, 5000) {
		rep(j, 5001) {
			dp[i][j] = INF;
		}
	}
}
void search(int i) {
	int res = 1;
	v[i].push_back(c[i]);
	rep(j, (int)G[i].size()) {
		search(G[i][j]);
		res += x[G[i][j]];
		rep(k, (int)v[G[i][j]].size()) {
			v[i].push_back(v[G[i][j]][k]);
		}
	}
	x[i] = res;
}
void dfs(int i) {
	if (G[i].size() == 0) {
		dp[i][0] = 0;
		dp[i][1] = c[i] - d[i];
		return;
	}
	dp[i][0] = c[i]-d[i];
	dp[i][1] = c[i] - d[i];
	int ri = 1;
	rep(j, (int)G[i].size()) {
		int v = G[i][j]; dfs(v);
		for (int k = 0; k <= ri + x[v]; k++) {
			cop[k] = dp[i][k];
		}
		for (int k = 0; k <= ri; k++) {
			for (int l = 0; l <= x[v]; l++) {
				cop[k + l] = min(cop[k + l], dp[i][k] + dp[v][l]);
			}
		}
		for (int k = 0; k <= ri + x[v];k++) {
			dp[i][k] = cop[k];
		}
		ri += x[v];
	}
	sort(v[i].begin(), v[i].end());
	ll sum = 0;
	for (int j = 1; j <= x[i]; j++) {
		sum += v[i][j - 1];
		dp[i][j] = min(dp[i][j], sum);
	}
}
int main() {
	init();
	int n; ll b; cin >> n >> b;
	rep(i, n) {
		cin >> c[i] >> d[i];
		if (i > 0) {
			int x; cin >> x; x--;
			G[x].push_back(i);
		}
	}
	search(0);
	dfs(0);
	int out = 0;
	rep(i, n + 1) {
		if (dp[0][i] <= b)out = i;
		//cout << dp[0][i] << endl;
	}
	cout << out << endl;
	return 0;
}