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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll d[1 << 19];
struct edge { int to; ll cost; int id; };
vector<edge> G[1 << 19];
queue<int> ans;
bool vused[1 << 19];
bool eused[1 << 19];
int main() {
	/*cin.tie(0);
	ios::sync_with_stdio(false);*/
	int n, m, k; cin >> n >> m >> k;
	rep(i, m) {
		int u, v; 
		//cin >> u >> v;
		scanf(" %d %d", &u, &v);
		u--; v--;
		ll c; 
		//cin >> c;
		scanf(" %lld", &c);
		G[u].push_back({ v,c,i + 1 });
		G[v].push_back({ u,c,i + 1 });
	}
	fill(d, d + n, INF);
	d[0] = 0;
	priority_queue<LP, vector<LP>, greater<LP>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		LP x = q.top(); q.pop();
		int id = x.second; ll nd = x.first;
		if (d[id] < nd)continue;
		rep(j, (int)G[id].size()) {
			int to = G[id][j].to;
			ll nexd = nd+G[id][j].cost;
			if (nexd < d[to]) {
				d[to] = nexd;
				q.push({ d[to],to });
			}
		}
	}
	vused[0] = true;
	queue<int> que; que.push(0);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		rep(i, (int)G[v].size()) {
			int to = G[v][i].to;
			if (vused[to])continue;
			if (d[to] == d[v] + G[v][i].cost) {
				que.push(to);
				vused[to] = true;
				eused[G[v][i].id] = true;
				ans.push(G[v][i].id);
			}
		}
	}
	rep1(i, m) {
		if (!eused[i]) {
			ans.push(i);
		}
	}
	cout << k << endl;
	rep(i, k) {
		/*if (i > 0)cout << " ";
		cout << ans.front(); ans.pop();*/
		if (i > 0) {
			printf(" ");
		}
		printf("%d", ans.front()); ans.pop();
	}
	printf("\n");
	return 0;
}