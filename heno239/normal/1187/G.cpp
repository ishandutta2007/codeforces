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

typedef long long ll;
#define int long long

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;



const int sz = 3000;

int c, d;

struct edge {
	int to, cap, cnt, rev;
};
vector<edge> G[50*sz+2];
P par[50*sz+2];
int dist[50*sz+2];

void add_edge(int from, int to,int cap=mod) {
	rep(i, sz - 1) {
		int a = i * 50 + from;
		int b = i * 50 + to + 50;

		G[a].push_back({ b,cap,0,(int)G[b].size() });
		G[b].push_back({ a,0,0,(int)G[a].size()-1});
	}
}
void init(int n) {
	rep(i, n) {
		rep(j, sz - 1) {
			int a = j * 50 + i;
			int b = a + 50;
			G[a].push_back({ b,mod,mod,(int)G[b].size() });
			G[b].push_back({ a,0,-mod,(int)G[a].size() - 1 });
		}
	}
}
int minimum_road(int s, int t) {
	fill(par, par + 50*sz+2, P{ -1,-1 });
	fill(dist, dist + 50*sz+2, INF);
	dist[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q; q.push({ 0,s });
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int id = p.second; 
		//cout << id<<" "<<p.first << endl;
		if (id == t)continue;
		if (p.first > dist[id])continue;
		rep(j, G[id].size()) {
			if (G[id][j].cap > 0) {
				int to = G[id][j].to;
				int cnt = G[id][j].cnt;
				int cost;
				if (cnt >= mod/2) {
					cost = c;
				}
				else if (cnt <= -mod / 2) {
					cost = -c;
				}
				else if (cnt >= 0) {
					cost = c + d * (2 * cnt + 1);
				}
				else {
					cost = -c + d * (2 * cnt + 1);
				}
				int nd = p.first + cost;
				if (nd < dist[to]) {
					dist[to] = nd;
					par[to] = { id,j };
					q.push({ dist[to],to });
				}
			}
		}
	}
	int cur = t;
	//cout << "? " << nt << endl;
	while (cur != s) {
		int p = par[cur].first, j = par[cur].second;
		//cout << p << " " << j << endl;
		G[p][j].cap--; G[p][j].cnt++;
		if (G[p][j].rev >= 0) {
			edge &e = G[cur][G[p][j].rev];
			e.cap++; e.cnt--;
		}
		cur = p;
	}
	return dist[t];
}
int minimum_cost_flow(int s, int t, int k) {
	ll ret = 0;
	rep(i, k) {
		int z = minimum_road(s, t);
		ret += z;
	}
	return ret;
}

void solve() {
	int n, m, k; cin >> n >> m >> k >> c >> d;
	vector<int> a(k); 
	rep(i, k) {
		cin >> a[i]; a[i]--;
	}
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		add_edge(a, b); add_edge(b, a);
	}
	init(n);
	int s = 50 * sz; int t = s + 1;
	rep(i, k) {
		G[s].push_back({ a[i],1,mod,(int)G[a[i]].size() });
		G[a[i]].push_back({ s,0,-mod,(int)G[s].size() - 1 });
	}
	rep(i, sz) {
		G[50 * i].push_back({ t,mod,mod,(int)G[t].size() });
		G[t].push_back({ 50 * i,0,-mod,(int)G[50 * i].size() - 1 });
	}
	int ans = minimum_cost_flow(s,t,k);
	ans -= 2 * c*k;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}