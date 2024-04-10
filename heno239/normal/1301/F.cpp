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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dist[40][1000100];

int col[1000][1000];

struct edge {
	int to, cost;
};
vector<edge> G[1000100];

void solve() {
	int h, w, k; cin >> h >> w >> k;
	rep(i, h)rep(j, w) {
		cin >> col[i][j];
		col[i][j]--;
	}
	rep(i, h)rep(j, w) {
		int id = i * w + j;
		rep(d, 4) {
			int nx = i + dx[d];
			int ny = j + dy[d];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
			int to = nx * w + ny;
			G[id].push_back({ to,2 });
		}
		G[id].push_back({ h*w + col[i][j],1 });
		G[h*w + col[i][j]].push_back({ id,1 });
	}
	rep(l, k) {
		rep(i, h*w+k)dist[l][i] = mod;
		dist[l][h*w + l] = 0;
		queue<int> cur, nex, nex2;
		cur.push({ h*w + l });
		while (!cur.empty()||!nex.empty()) {
			while(!cur.empty()){
				int id = cur.front(); cur.pop();
				//cout << l << " " << id << endl;
				for (edge &e : G[id]) {
					int nd = dist[l][id] + e.cost;
					if (nd < dist[l][e.to]) {
						dist[l][e.to] = nd;
						if (e.cost == 1)nex.push(e.to);
						else nex2.push(e.to);
					}
				}
			}
			swap(cur, nex);
			swap(nex, nex2);
		}
	}
	//cout << dist[0][0] << endl;
	int q; cin >> q;
	rep(i, q) {
		int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
		sx--; sy--; gx--; gy--;
		int ans = 2*(abs(gx - sx) + abs(gy - sy));
		rep(l, k) {
			ans = min(ans, dist[l][sx*w+sy] + dist[l][gx*w+gy]);
		}
		assert(ans % 2 == 0);
		cout << ans/2 << endl;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}