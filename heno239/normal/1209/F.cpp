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
#include<complex>
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
const ld pi = acos(-1.0);

const int sz = 500;

struct edge {
	int to; int id;
};
vector<edge> G[1 << 20];
int dist[1 << 20];

bool chked[1 << 20];
ll ans[1 << 20];

struct edge2 {
	int id, fr, to;
};
typedef pair<P, P> speP;
ll t10[7];
void solve() {
	t10[0] = 1;
	rep(i, 6) {
		t10[i + 1] = t10[i] * 10;
	}
	int n, m; cin >> n >> m;
	int cur = n;
	rep1(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		string s = to_string(i);
		int las = a;
		int len = s.size();
		rep(j, (int)s.size() - 1) {
			G[las].push_back({ cur,s[j] - '0' });
			G[cur].push_back({ las,s[len - 1 - j] - '0' });
			las = cur;
			cur++;
		}
		G[las].push_back({ b,s.back() - '0' });
		G[b].push_back({ las,s[0] - '0' });
	}

	fill(dist, dist + cur, mod);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int id = p.second;
		if (dist[id] < p.first)continue;
		rep(j, G[id].size()) {
			int to = G[id][j].to;
			int cost = 1;
			if (cost + p.first < dist[to]) {
				dist[to] = cost + p.first;
				q.push({ dist[to],to });
			}
		}
	}
	stack<vector<edge2>> st;
	ans[0] = 0;
	chked[0] = true;
	vector<edge2> v[10];
	rep(i, G[0].size()) {
		int to = G[0][i].to;
		int id = G[0][i].id;
		if (dist[0] + 1 != dist[to])continue;
		v[id].push_back({ id,0,to });
	}
	per(i, 10) {
		if (!v[i].empty()) {
			st.push(v[i]);
		}
	}
	while (!st.empty()) {
		rep(i, 10)v[i].clear();
		vector<edge2> u = st.top(); st.pop();
		rep(j, u.size()) {
			int fr = u[j].fr;
			int to = u[j].to;
			if (chked[to])continue;
			chked[to] = true;
			ans[to] = (ans[fr] * 10 + u[j].id) % mod;
			rep(i, G[to].size()) {
				int tto = G[to][i].to;
				int iid = G[to][i].id;
				if (dist[to] + 1 != dist[tto])continue;
				v[iid].push_back({ iid,to,tto });
			}
		}
		per(i, 10) {
			if (!v[i].empty())st.push(v[i]);
		}
	}
	rep1(i, n - 1) {
		cout << ans[i] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}