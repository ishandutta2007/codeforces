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
const ll mod = 998244353;
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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
const int mn = 300001;
bool used[mn];
ll a[mn];
vector<int> G[mn];
int n;
ll ma = -INF;
ll s[mn];
ll dfs(int id) {
	used[id] = true;
	ll res = a[id];
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to])continue;
		res += dfs(to);
	}
	s[id] = max(ma, res);
	ma = max(ma, res);
	return max(res, (ll)0);
}
int cnt = 0;
ll dfs2(int id) {
	used[id] = true;
	ll res = a[id];
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to])continue;
		res += dfs2(to);
	}
	if (ma == res) {
		cnt++; return 0;
	}
	else return max((ll)0, res);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n-1) {
		int b, c; cin >> b >> c; b--; c--;
		G[b].push_back(c);
		G[c].push_back(b);
	}
	dfs(0);
	fill(used, used +n,false);
	dfs2(0);
	cout << ma * cnt << " " << cnt << endl;
	//stop
	return 0;
}