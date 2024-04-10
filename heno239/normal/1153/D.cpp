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
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int n;
vector<int> G[1 << 19];
bool b[1 << 19];
int calcleaf(int id) {
	if (G[id].size() == 0)return 1;
	int ret = 0;
	rep(j, G[id].size()) {
		ret += calcleaf(G[id][j]);
	}
	return ret;
}
int dfs(int id) {
	if (G[id].size() == 0)return 1;
	int ret;
	if (b[id]) {
		ret = mod;
		rep(j, G[id].size()) {
			ret = min(ret, dfs(G[id][j]));
		}
	}
	else {
		ret = 0;
		rep(j, G[id].size()) {
			ret += dfs(G[id][j]);
		}
	}
	return ret;
}
void solve() {
	cin >> n;
	rep(i, n) {
		int t; cin >> t;
		if (t)b[i] = true;
	}
	rep1(i, n - 1) {
		int a; cin >> a; a--;
		G[a].push_back(i);
	}
	int c = calcleaf(0);
	int u = dfs(0);
	cout << c - u + 1 << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}