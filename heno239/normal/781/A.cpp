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

int n,k;
vector<int> G[1 << 18];
int ans[1 << 18];
bool f;

void dfs(int v, int from,int colfrom) {
	if (v == 0) {
		ans[v] = 1;
	}
	if ((int)G[v].size() + 1 > k) {
		f = false; return;
	}
	int cur = 1;
	rep(j, G[v].size()) {
		int to = G[v][j];
		if (to == from)continue;
		while (cur == colfrom || cur == ans[v]) {
			cur++; if (cur > k)cur = 1;
		}
		ans[to] = cur; dfs(to, v, ans[v]);
		cur++; if (cur > k)cur = 1;
	}
}

void solve() {
	cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	int le = 0, ri = n + 1;
	while (ri - le > 1) {
		k = (ri + le) / 2;
		f = true;
		dfs(0, -1,-1);
		if (f) {
			ri = k;
		}
		else {
			le = k;
		}
	}
	cout << ri << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}