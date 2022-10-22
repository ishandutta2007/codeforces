#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	rep(i,0,n-1) {
		int u, v;
		cin >> u >> v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int>> children(n);
	vector<int> parent(n, -1);
	vector<int> ordered;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		ordered.push_back(cur);
		q.pop();
		for (int to : adj[cur]) {
			if (to == parent[cur])
				continue;
			parent[to] = cur;
			children[cur].push_back(to);
			q.push(to);
		}
	}
	reverse(all(ordered));
	vector<vector<int>> buckets(n+1);
	rep(i,1,n+1) {
		int b = 0;
		int j = i;
		while (j > 1) {
			j /= 2;
			++b;
		}
		buckets[b].push_back(i);
	}
	vector<int> ans(n, -1);
	reverse(all(buckets));
	for (auto bucket : buckets) {
		vector<bool> used(n);
		int i = 0;
		for (int x : ordered) {
			if (i == sz(bucket))
				break;
			if (ans[x] != -1)
				continue;
			bool ok = true;
			for (int c : children[x]) {
				if (used[c])
					ok = false;
			}
			if (ok) {
				used[x] = true;
				ans[x] = bucket[i++];
			}
		}
	}
	rep(i,0,n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}