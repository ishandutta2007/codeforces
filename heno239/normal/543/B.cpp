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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

vector<int> G[3000];
int dist[3000][3000];
bool used[3000];

void calcdist(int n) {
	rep(i, n) {
		fill(used, used + n, false);
		int tmp = 0;
		queue<int> q; q.push(i); used[i] = true;
		while (!q.empty()) {
			int len = q.size();
			rep(aa, len) {
				int id = q.front(); q.pop();
				dist[i][id] = tmp;
				rep(j, G[id].size()) {
					int to = G[id][j];
					if (!used[to]) {
						used[to] = true; q.push(to);
					}
				}
			}
			tmp++;
		}
	}
}
void solve(){
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	calcdist(n);
	int s[2], t[2], l[2];
	rep(i, 2) {
		cin >> s[i] >> t[i] >> l[i];
		s[i]--; t[i]--;
	}
	if (dist[s[0]][t[0]] > l[0]) {
		cout << -1 << endl; return;
	}
	if (dist[s[1]][t[1]] > l[1]) {
		cout << -1 << endl; return;
	}

	int ans = dist[s[0]][t[0]]+dist[s[1]][t[1]];
	for (int xs = 0; xs < n; xs++) {
		for (int xt = 0; xt < n; xt++) {
			int ds0 = dist[s[0]][xs];
			int ds1 = dist[s[1]][xs];
			int dt0 = dist[xt][t[0]];
			int dt1 = dist[xt][t[1]];
			int d = dist[xs][xt];
			if (ds0 + dt0 + d > l[0])continue;
			if (ds1 + dt1 + d > l[1])continue;
			ans = min(ans, ds0 + ds1 + dt0 + dt1+d);
		}
	}
	for (int xs = 0; xs < n; xs++) {
		for (int xt = 0; xt < n; xt++) {
			int ds0 = dist[s[0]][xs];
			int dt1 = dist[t[1]][xs];
			int dt0 = dist[xt][t[0]];
			int ds1 = dist[xt][s[1]];
			int d = dist[xs][xt];
			if (ds0 + dt0 + d > l[0])continue;
			if (ds1 + dt1 + d > l[1])continue;
			ans = min(ans, ds0 + ds1 + dt0 + dt1 + d);
		}
	}
		cout << m - ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}