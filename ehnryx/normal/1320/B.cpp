//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
vector<int> adj[N], rev[N];
int dist[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}

	int k;
	cin >> k;
	int V[k];
	for(int i=0; i<k; i++) {
		cin >> V[i];
	}

	memset(dist, -1, sizeof dist);

	queue<int> bfs;
	bfs.push(V[k-1]);
	dist[V[k-1]] = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		for(int v : rev[u]) {
			if(dist[v] != -1) continue;
			dist[v] = dist[u] + 1;
			bfs.push(v);
		}
	}

	int minv = 0;
	int maxv = 0;
	for(int i=1; i<k; i++) {
		if(dist[V[i]] >= dist[V[i-1]]) {
			minv++;
			maxv++;
		} else {
			for(int w : adj[V[i-1]]) {
				if(w != V[i] && dist[w] == dist[V[i]]) {
					maxv++;
					break;
				}
			}
		}
	}
	cout << minv << " " << maxv << nl;

	return 0;
}