#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;
int a[N];
vector<int> adj[N];
int ford[N], revd[N];

int rmq[2*N];
void insert(int i, int v) {
	rmq[i+=N] = v;
	for(i/=2;i;i/=2) {
		rmq[i] = max(rmq[2*i], rmq[2*i+1]);
	}
}
int query(int l, int r) {
	int res = -1;
	for(l+=N,r+=N;l<r;l/=2,r/=2) {
		if(l&1) res = max(res, rmq[l++]);
		if(r&1) res = max(res, rmq[--r]);
	}
	return res;
}

void dijkstra(int s, int d[]) {
	fill(d, d+N, -1);
	queue<int> bfs;
	bfs.push(s);
	d[s] = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		for(int v:adj[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				bfs.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++) {
		cin >> a[i];
	}
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dijkstra(1, ford);
	dijkstra(n, revd);

	int best = -1;
	vector<pair<int,int>> vals;
	for(int i=0; i<k; i++) {
		vals.push_back(make_pair(ford[a[i]], a[i]));
	}
	sort(vals.begin(), vals.end(), greater<pair<int,int>>());
	int maxv = revd[vals[0].second];
	for(int i=1; i<k; i++) {
		best = max(best, maxv + 1 + vals[i].first);
		maxv = max(maxv, revd[vals[i].second]);
	}
	assert(best != -1);
	cout << min(best, ford[n]) << nl;

	return 0;
}