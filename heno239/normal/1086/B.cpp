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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n; ld s;
vector<P> G[1 << 17];
bool used[1 << 17];
ld v[1 << 17];
ld ev[1 << 17];
typedef pair<ld, int> pd;
ld sum = 0;
ld dfs(int id) {
	used[id] = true;
	vector<pd> c;
	rep(j, G[id].size()) {
		int to = G[id][j].first;
		if (used[to])continue;
		c.push_back({ dfs(to),G[id][j].second });
	}
	rep(i, c.size()) {
		if (c[i].first < 0.5) {
			ev[c[i].second] += 0.5 - c[i].first;
		}
	}
	if (id == 0 && c.size() == 1) {
		sum += 0.5;
	}
	if (c.size() == 0)return 0;
	else return 0.5;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(18);
	cin >> n >> s;
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back({ v,i }); G[v].push_back({ u,i });
	}
	dfs(0);
	rep(i, n - 1) {
		sum += ev[i];
	}
	cout << s / sum << endl;
	return 0;
}