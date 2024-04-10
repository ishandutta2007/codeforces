#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

struct DSU {
	int root[1000000];
	DSU() {
		memset(root, -1, sizeof(root));
	}
	int find(int i) {
		if (root[i] == -1) return i;
		return root[i] = find(root[i]);
	}
	void link(int i, int j) {
		if (find(i) == find(j)) return;
		root[find(i)] = find(j);
	}
};

struct Node {
	int start, length;
	int left, right;
	int type;
	Node() {}
	Node(int start, int len): start(start), length(len) {
		left = right = -1;
		type = -1;
	}
};

struct PQ {
	int len, start, id;
	PQ() {}
	PQ(int len, int start, int id): len(len), start(start), id(id) {}
	bool operator < (const PQ& other) const {
		if (len == other.len) return start > other.start;
		else return len < other.len;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	priority_queue<PQ> next;
	vector<Node> nodes;
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] != a[i-1]) {
			nodes.push_back(Node(start, i - start));
			if (nodes.size() > 1) {
				nodes.back().left = nodes.size()-2;
			}
			nodes.back().right = nodes.size();
			nodes.back().type = a[i-1];
			next.push(PQ(nodes.back().length, nodes.back().start, nodes.size()-1));
			start = i;
		}
	}
	nodes.push_back(Node(start, n - start));
	nodes.back().left = nodes.size()-2;
	nodes.back().type = a[n-1];
	next.push(PQ(nodes.back().length, nodes.back().start, nodes.size()-1));

	DSU dsu;

	vector<bool> vis(1000000);
	int ans = 0;
	while (!next.empty()) {
		PQ curr = next.top();
		next.pop();
		if (vis[dsu.find(curr.id)])
			continue;
		ans++;
		vis[dsu.find(curr.id)] = true;

		Node cur = nodes[curr.id];

		//cerr << "look at " << curr.id << " --> " << "I:" << cur.start << " " << "L:" << cur.length << " " << cur.left << " " << cur.right << " " << cur.type << endl;

		if (cur.left == -1 && cur.right == -1) {
			break;
		} else if (cur.left == -1) {
			nodes[cur.right].left = -1;
			continue;
		} else if (cur.right == -1) {
			nodes[cur.left].right = -1;
			continue;
		}

		nodes[cur.left].right = cur.right;
		nodes[cur.right].left = cur.left;
		if (nodes[cur.left].type == nodes[cur.right].type) {
			nodes.push_back(Node(nodes[cur.left].start, nodes[cur.left].length + nodes[cur.right].length));
			nodes.back().type = nodes[cur.left].type;
			nodes.back().left = nodes[cur.left].left;
			nodes.back().right = nodes[cur.right].right;
			if (nodes.back().left != -1) {
				nodes[nodes.back().left].right = nodes.size()-1;
				//cerr << "upd LEFT" << endl;
			}
			if (nodes.back().right != -1) {
				nodes[nodes.back().right].left = nodes.size()-1;
				//cerr << "upd RIGHT" << endl;
			}
			dsu.link(cur.left, nodes.size()-1);
			dsu.link(cur.right, nodes.size()-1);

			//cerr << "create new node " << nodes.size()-1 << " --> " << nodes.back().start << " " << nodes.back().length << " " << nodes.back().left << " " << nodes.back().right << " " << nodes.back().type << endl;
			next.push(PQ(nodes.back().length, nodes.back().start, nodes.size()-1));
		}
	}

	cout << ans << endl;

	return 0;
}