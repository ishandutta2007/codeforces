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
const ll mod = 998244353;
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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;


struct edge {
	int l, r; ll cost;
	bool operator<(const edge &e)const {
		return cost < e.cost;
	}
};

struct edge2 {
	int to; ll cost;
};
vector<edge2> G[1 << 18];

ll dist[1000];
int inv[1 << 18];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<edge> v;
	rep(i, m) {
		int l, r; ll c;
		cin >> l >> r >> c; l--; r--;
		v.push_back({ l,r,c });
	}
	sort(v.begin(), v.end());
	ll ans = INF; ll sup = INF;
	if (m > k) {
		ans = sup = v[k - 1].cost;
	}
	//cout << "!!!" << endl;
	rep(i, m) {
		if (v[i].cost >= sup)break;
		if (i >= k)break;
		int l = v[i].l, r = v[i].r;
		//cout << l << " " << r << " " << v[i].cost << endl;
		G[l].push_back({ r,v[i].cost });
		G[r].push_back({ l,v[i].cost });
	}

	vector<ll> cans;
	vector<bool> used(n,false);
	priority_queue<LP, vector<LP>, greater<LP>> que;
	rep(i, n) {
		if (G[i].size() == 0)continue;
		if (used[i])continue;
		vector<int> ids;
		queue<int> q;
		q.push(i); used[i] = true; inv[i] = 0; ids.push_back(i);
		while (!q.empty()) {
			int id = q.front(); q.pop();
			rep(j, G[id].size()) {
				int to = G[id][j].to;
				if (used[to])continue;
				used[to] = true;
				inv[to] = ids.size();
				ids.push_back(to);
				q.push(to);
			}
		}
		int len = ids.size();
		rep(j, len) {
			fill(dist, dist + len, INF);
			dist[j] = 0; que.push({ 0,j });
			while (!que.empty()) {
				LP p = que.top(); que.pop();
				int id = p.second;
				if (p.first > dist[id])continue;
				rep(l, G[ids[id]].size()) {
					int to = G[ids[id]][l].to;
					to = inv[to];
					ll nd = p.first + G[ids[id]][l].cost;
					if (nd < dist[to]) {
						dist[to] = nd;
						que.push({ nd,to });
					}
				}
			}
			Rep(l, j + 1, len) {
				cans.push_back(dist[l]);
			}
		}
	}
	sort(cans.begin(), cans.end());
	//rep(i, cans.size())cout << cans[i] << endl;
	if (cans.size() >= k) {
		ans = min(ans, cans[k - 1]);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}