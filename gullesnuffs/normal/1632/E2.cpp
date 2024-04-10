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

struct Tree {
	int root;
	vector<vector<int>> adj;
	int n;
	vector<int> dis;
	vector<int> parent;
	//vector<vector<int>> parent_step;

	Tree(vector<vector<int>> _adj, int _root) {
		adj = _adj;
		root = _root;
		n = sz(adj);
		dis.resize(n);
		parent = vector<int>(n, -1);
		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int to : adj[node]) {
				if (to == parent[node])
					continue;
				dis[to] = dis[node]+1;
				parent[to] = node;
				q.push(to);
			}
		}
		/*parent_step.resize(20);
		rep(i,0,n)
			parent_step[0].push_back(parent[i]);
		rep(i,1,20)
			rep(j,0,n) {
				if (parent_step[i][j-1] == -1)
					parent_step[i].push_back(-1);
				else
					parent_step[i].push_back(parent_step[i-1][parent_step[i-1][j]]);
			}*/
	}

	/*int get_parent_at_depth(int node, int d) {
		rrep(i,20,0) {
			if (dis[node]-(1<<i) >= d) {
				node = parent_step[i][node];
			}
		}
		return node;
	}*/
};

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
	Tree t1(adj, 0);
	vector<pair<int, int>> dis_nodes;
	rep(i,0,n)
		dis_nodes.emplace_back(t1.dis[i], i);
	sort(all(dis_nodes));
	reverse(all(dis_nodes));
	int b = dis_nodes[0].second;
	Tree t2(adj, b);
	int max_dis2 = 0;
	int prevw = n+1;
	vector<int> ans(n+1, t1.dis[b]);
	vector<pair<int, int>> p;
	rep(i,0,n-1) {
		int node = dis_nodes[i].second;
		max_dis2 = max(max_dis2, t2.dis[node]);
		int try_ans = dis_nodes[i+1].first;
		p.emplace_back(try_ans, max_dis2);
		/*int maxw = try_ans - (max_dis2+1)/2;
		while (maxw < prevw && prevw > 1) {
			--prevw;*/
		/*rep(prevw,1,n+1) {
			ans[prevw] = min(ans[prevw], max(try_ans, (max_dis2+1)/2+prevw));
		}*/
	}
	rep(w,1,n+1) {
		int lo = -1, hi = sz(p);
		while (hi-lo > 1) {
			int mid = (lo+hi)/2;
			int try_ans = p[mid].first;
			int max_dis2 = p[mid].second;
			int x = (max_dis2+1)/2+w;
			ans[w] = min(ans[w], max(try_ans, x));
			if (try_ans < x) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
	}
	rep(i,1,n+1)
		cout << ans[i] << " ";
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) solve();
}