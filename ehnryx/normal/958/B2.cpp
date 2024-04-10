#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
	int id, len;
	Node() {}
	Node(int i, int l): id(i), len(l) {}
	bool operator < (const Node& n) const {
		return len > n.len;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> deg(n+1, 0);
	unordered_set<int> adj[n+1];

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	vector<int> leaves;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) leaves.push_back(i);
	}

	vector<int> dist(n+1, -1);
	vector<int> jump(n+1, -1);
	vector<int> child(n+1, -1);
	vector<int> revr(n+1, -1);

	priority_queue<Node> least;
	for (int leaf : leaves) {
		int pre = leaf;
		int v = *adj[leaf].begin(); 
		int len = 1;
		while (deg[v] == 2) {
			len++;
			for (int it : adj[v]) {
				if (it != pre) {
					pre = v;
					v = it;
					break;
				}
			}
		}
		least.push(Node(leaf, len));
		dist[leaf] = len;
		jump[leaf] = v;
		child[leaf] = pre;
		revr[pre] = leaf;
	}

	vector<int> ans(n+1);
	int pos = leaves.size();
	for (int i = pos; i <= n; i++) {
		ans[i] = n;
	}

	while (--pos > 1) {
		Node cur = least.top();
		least.pop();
		if (dist[cur.id] != cur.len) {
			++pos;
			continue;
		}

		adj[jump[cur.id]].erase(child[cur.id]);
		deg[jump[cur.id]]--;
		ans[pos] = ans[pos+1] - cur.len;

		if (adj[jump[cur.id]].size() == 2) {
			int connect = -1;
			for (int v : adj[jump[cur.id]]) {
				if (revr[v] != -1) {
					connect = v;
					break;
				}
			}

			if (connect != -1) {
				int leaf = revr[connect];
				int pre = connect;
				int v = jump[cur.id];
				int len = dist[leaf];
				while (deg[v] == 2) {
					len++;
					for (int it : adj[v]) {
						if (it != pre) {
							pre = v;
							v = it;
							break;
						}
					}
				}
				least.push(Node(leaf, len));
				dist[leaf] = len;
				jump[leaf] = v;
				child[leaf] = pre;
				revr[pre] = leaf;
			}
		}
	}
	ans[1] = 1;

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}