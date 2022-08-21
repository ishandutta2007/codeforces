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
const ll mod = 1000000009;
const ll INF = mod * mod;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using ld = long double;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

struct edge { int to; int cap; int rev; };
struct Dinic {
private:
	int n;
	vector<vector<edge>> v;
	vector<int> dist, iter;
public:
	Dinic(int sz) :n(sz), v(sz), dist(sz), iter(sz) {}

	void addedge(int from, int to, int cap) {
		int x = v[to].size(), y = v[from].size();
		v[from].push_back({ to,cap,x });
		v[to].push_back({ from,0,y });
	}

	void bfs(int s) {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			rep(i, v[x].size()) {
				edge &e = v[x][i];
				if (e.cap>0 && dist[e.to]<0) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
	}

	int dfs(int x, int t, int f) {
		if (x == t)return f;
		for (int& i = iter[x]; i<(int)v[x].size(); ++i) {
			edge& e = v[x][i];
			if (e.cap>0 && dist[x]<dist[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d>0) {
					e.cap -= d;
					v[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			bfs(s);
			if (dist[t]<0)return flow;
			fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(s, t, mod))>0)flow += f;
		}
	}
};


void solve() {
	int m, n, k, t; cin >> m >> n >> k >> t;
	vector<int> a(m);
	rep(i, m)cin >> a[i];
	sort(all(a), greater<int>());
	vector<int> l(k), r(k), d(k);
	rep(i, k) {
		cin >> l[i] >> r[i] >> d[i];
	}
	int le = 0, ri = m + 1;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		int val = a[mid - 1];
		vector<int> cnt(n + 2, 0);
		rep(i, k) {
			if (d[i] > val) {
				if (l[i] <= r[i]) {
					cnt[l[i]]++;
					cnt[r[i] + 1]--;
				}
			}
		}
		int num = 0;
		rep(i, n+1) {
			cnt[i + 1] += cnt[i];
			if (cnt[i])num += 3;
			else num++;
		}
		if (num <= t) {
			le = mid;
		}
		else {
			ri = mid;
		}
	}
	cout << le << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	stop
	return 0;
}