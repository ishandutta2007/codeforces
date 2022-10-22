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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
	int i, t; ll d;
	bool operator < (const Node& o) const {
		return d > o.d;
	}
};

const int N = 1e4;
const int M = 1e3;
ll dist[N][M];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	int a[m];
	for(int i=0; i<m; i++) {
		cin >> a[i];
	}
	sort(a, a+m);
	int g, r;
	cin >> g >> r;

	memset(dist, INF, sizeof dist);
	priority_queue<Node> bfs;
	bfs.push({0, 0, 0});
	dist[0][0] = 0;
	while(!bfs.empty()) {
		auto [i, t, d] = bfs.top();
		bfs.pop();
		if(dist[i][t] != d) {
			continue;
		}
		if(i == m-1) {
			cout << d - r << nl;
			return 0;
		}
		int nt = (t + a[i+1] - a[i] == g ? 0 : t + a[i+1] - a[i]);
		ll nxt = d + a[i+1] - a[i] + (t == 0 ? r : 0);
		if(nt < g && nxt < dist[i+1][nt]) {
			dist[i+1][nt] = nxt;
			bfs.push({i+1, nt, nxt});
		}
		if(i > 0) {
			nt = (t + a[i] - a[i-1] == g ? 0 : t + a[i] - a[i-1]);
			nxt = d + a[i] - a[i-1] + (t == 0 ? r : 0);
			if(nt < g && nxt < dist[i-1][nt]) {
				dist[i-1][nt] = nxt;
				bfs.push({i-1, nt, nxt});
			}
		}
	}

	cout << -1 << nl;

	return 0;
}