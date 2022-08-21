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

struct edge { int a, b,id; };
edge e[1 << 18];
int c[1 << 18];
struct edge2 {
	int to, id;
};
int ans[1 << 18];
vector<edge2> G[1 << 18];
int num;
void dfs(int id, int fr,int col) {
	int tmp = 1;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (to == fr)continue;
		if (tmp == col)tmp++;
		if (tmp > num)tmp = 1;
		ans[G[id][j].id] = tmp;
		dfs(to, id, tmp); tmp++;
	}
}
void solve() {
	int n, k; cin >> n >> k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		e[i] = { a,b,i };
		c[a]++; c[b]++;
		G[a].push_back({ b,i });
		G[b].push_back({ a,i });
	}
	int le = -1, ri = n-1;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		int cnt = 0;
		rep(i, n) {
			if (c[i] > mid)cnt++;
		}
		//cout << mid << " " << cnt << endl;
		if (cnt > k) {
			le = mid;
		}
		else {
			ri = mid;
		}
	}
	num = ri;
	dfs(0, -1,-1);
	cout << num << endl;
	rep(i, n - 1) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}