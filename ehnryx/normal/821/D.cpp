#include <bits/stdc++.h>
using namespace std;

//#define debug

#define ll long long
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

struct Rect {
	int top;
	int bot;
	int left;
	int right;
	Rect() {}
	Rect(int a, int b, int c, int d) {
		top = a;
		bot = b;
		left = c;
		right = d;
	}
	void update(const Rect& other) {
		top = max(top, other.top);
		bot = min(bot, other.bot);
		left = min(left, other.left);
		right = max(right, other.right);
	}
};

typedef pair<int,int> Cell;
struct DSU {
	int start, dest;
	vector<int> root;
	vector<int> weight;
	vector<Rect> bound;
	map<Cell,int> m;
	DSU() {
		start = -1;
		dest = -1;
	}

	int insert(int a, int b, bool linkit, bool isstart, bool isend) {
		int curr = root.size();
		if (isstart) start = curr;
		if (isend) dest = curr;
		m.insert(pair<Cell,int>(Cell(a,b),curr));
		root.push_back(-1);
		weight.push_back(1);
		bound.push_back(Rect(a,a,b,b));
		if (linkit) {
			#ifdef debug
			cerr << endl << "curr: " << a << " " << b << endl;
			cerr << "up " << m.count(Cell(a-1, b)) << endl;
			cerr << "down " << m.count(Cell(a+1, b)) << endl;
			cerr << "left " << m.count(Cell(a, b-1)) << endl;
			cerr << "right " << m.count(Cell(a, b+1)) << endl;
			#endif
			if (m.count(Cell(a-1,b)))
				link(m[Cell(a-1,b)], curr);
			if (m.count(Cell(a+1,b)))
				link(m[Cell(a+1,b)], curr);
			if (m.count(Cell(a,b-1)))
				link(m[Cell(a,b-1)], curr);
			if (m.count(Cell(a,b+1)))
				link(m[Cell(a,b+1)], curr);
		}

		return find(curr);
	}
	int find(int i) {
		if (root[i] == -1) return i;
		else return root[i] = find(root[i]);
	}
	void link(int i, int j) {
		int a = find(i);
		int b = find(j);
		if (a == b) return;
		if (weight[a] < weight[b]) swap(a,b);
		root[b] = a;
		weight[a] += weight[b];
		bound[a].update(bound[b]);
		if (start == b) start = a;
		if (dest == b) dest = a;
	}
	bool connected(int i, int j, int destpos, bool islit) {
		#ifdef debug
		cerr << "connected? " << i << " " << j << " dest: " << destpos << " islit: " << islit << endl;
		#endif
		if (!islit && (destpos == i || destpos == j)) {
			if ((bound[i].top < bound[j].bot-1 || bound[j].top < bound[i].bot-1) && (bound[i].right < bound[j].left-1 || bound[j].right < bound[i].left-1))
				return false;
			else return true;
		}
		else {
			if ((bound[i].top < bound[j].bot-2 || bound[j].top < bound[i].bot-2) && (bound[i].right < bound[j].left-2 || bound[j].right < bound[i].left-2))
				return false;
			else return true;
		}
	}
};

int dijkstra(int start, int end, const vector<vector<int>>& graph) {
	struct Node {
		int i;
		int dist;
		Node() {}
		Node(int ii, int dd) {
			i = ii;
			dist = dd;
		}
		bool operator < (const Node& other) const {
			return this->dist > other.dist;
		}
	};
	int dist[graph.size()];
	memset(dist, INF, sizeof(dist));
	Node curr;
	priority_queue<Node> next;
	next.push(Node(start, 0));
	while (!next.empty()) {
		curr = next.top();
		next.pop();
		if (curr.i == end) return curr.dist;
		if (curr.dist < dist[curr.i]) {
			dist[curr.i] = curr.dist;
			for (int neighbour: graph[curr.i]) {
				next.push(Node(neighbour, curr.dist+1));
			}
		}
	}
	return -1;
}

The story of lame:

	int a, b;
	int rows, cols, k, curr;
	cin >> rows >> cols >> k;
	bool found = false;
	DSU dsu;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		if (a == 1 && b == 1) dsu.insert(a, b, true, true, false);
		else if (a == rows && b == cols) {
			dsu.insert(a, b, true, false, true);
			found = true;
		}
		else dsu.insert(a, b, true, false, false);
	}
	// get nodes
	vector<int> nodes;
	int destpos, startpos;
	for (int i = 0; i < k; i++) {
		if (dsu.root[i] == -1) {
			if (dsu.start == i)
				startpos = nodes.size();
			if (dsu.dest == i)
				destpos = nodes.size();
			nodes.push_back(i);
		}
	}
	if (!found) {
		destpos = nodes.size();
		nodes.push_back(dsu.insert(rows, cols, false, false, true));
	}
	// build graph
	int vertices = nodes.size();
	vector<vector<int>> graph(vertices);
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < i; j++) {
			if (dsu.connected(nodes[i], nodes[j], nodes[destpos], found)) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	#ifdef debug
	cerr << "start: " << startpos << "  end: " << destpos << endl;
	for (int i = 0; i < vertices; i++) {
		cerr << i << ": "; for (int it: graph[i]) cerr << it << " ";
		cerr << endl;
	}
	#endif
	cout << dijkstra(startpos, destpos, graph) << endl;

The End