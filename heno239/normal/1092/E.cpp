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
bool used[1 << 10];
bool cused[1 << 10];
int n,m; vector<int> G[1 << 10];
int maximum(int id) {
	fill(cused, cused + n, false);
	queue<int> q; q.push(id); cused[id] = true;
	int res = -1;
	while (!q.empty()) {
		res++;
		int len = q.size();
		rep(i, len) {
			int x = q.front(); q.pop();
			rep(j, G[x].size()) {
				int to = G[x][j];
				if (cused[to])continue;
				cused[to] = true; q.push(to);
			}
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n>>m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<P> v;
	int ans = 0;
	rep(i, n) {
		if (used[i])continue;
		used[i] = true;
		vector<int> u;
		queue<int> q; q.push(i); u.push_back(i);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			rep(j, G[x].size()) {
				int to = G[x][j];
				if (used[to])continue;
				q.push(to);
				u.push_back(to);
				used[to] = true;
			}
		}
		int mi = 10000; int id = -1;
		rep(j,u.size()) {
			int d = maximum(u[j]);
			ans = max(ans, d);
			if (mi > d) {
				mi = d; id = u[j];
			}
		}
		v.push_back({ mi,id });
	}
	sort(v.begin(), v.end()); int num = v.size();
	rep(i, num - 1) {
		ans = max(ans, 1 + v[num - 1].first + v[i].first);
	}
	rep(i, num - 1) {
		Rep(j, i + 1, num - 1) {
			ans = max(ans, 2 + v[i].first + v[j].first);
		}
	}
	cout << ans << endl;
	rep(i, num - 1) {
		cout << v[i].second + 1 << " " << v[num-1].second+1 << endl;
	}
	return 0;
}