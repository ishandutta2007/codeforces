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
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

const int N = 2e5;
const int M = 2e5;
const int Q = 2e5;

struct SegTree {
	struct Node {
		ll dx;
		ll min;
		bool lazy;
		Node() {
			lazy = false;
			dx = 0;
		}

		void propagate(Node& left, Node& right) {
			left.min += dx;
			left.dx += dx;
			right.min += dx;
			right.dx += dx;
			left.lazy = right.lazy = true;
			this->lazy = false;
			this->dx = 0;
		}
	};

	static const int length = 1<<18;
	Node nodes[2*length];
	SegTree() {}

	void build(int n, ll arr[]) {
		for (int i = 1; i <= n; i++) {
			nodes[length+i-1].min = arr[i];
		}
		for (int i = length-1; i > 0; i--) {
			nodes[i].min = min(nodes[2*i].min, nodes[2*i+1].min);
		}
	}

	void replace(int left, int right, ll x) {
		replace(left, right, x, 1, length);
	}
	void replace(int left, int right, ll x, int start, int end) {
		int i = (length+left-1)/(end-start+1);
		if (left == start && right == end) {
			nodes[i].min = x;
			nodes[i].lazy = true;
			return;
		}
		if (nodes[i].lazy) {
			nodes[i].propagate(nodes[2*i], nodes[2*i+1]);
		}

		int mid = (start+end)/2;
		if (right <= mid) {
			replace(left, right, x, start, mid);
		} else if (left > mid) {
			replace(left, right, x, mid+1, end);
		} else {
			replace(left, mid, x, start, mid);
			replace(mid+1, right, x, mid+1, end);
		}
		nodes[i].min = min(nodes[2*i].min, nodes[2*i+1].min);
	}

	void update(int left, int right, ll dx) {
		update(left, right, dx, 1, length);
	}
	void update(int left, int right, ll dx, int start, int end) {
		int i = (length+left-1)/(end-start+1);
		if (left == start && right == end) {
			nodes[i].dx += dx;
			nodes[i].min += dx;
			nodes[i].lazy = true;
			return;
		}
		if (nodes[i].lazy) {
			nodes[i].propagate(nodes[2*i], nodes[2*i+1]);
		}

		int mid = (start+end)/2;
		if (right <= mid) {
			update(left, right, dx, start, mid);
		} else if (left > mid) {
			update(left, right, dx, mid+1, end);
		} else {
			update(left, mid, dx, start, mid);
			update(mid+1, right, dx, mid+1, end);
		}
		nodes[i].min = min(nodes[2*i].min, nodes[2*i+1].min);
	}

	ll query_min(int left, int right) {
		return query_min(left, right, 1, length);
	}
	ll query_min(int left, int right, int start, int end) {
		int i = (length+left-1)/(end-start+1);
		if (left == start && right == end) {
			return nodes[i].min;
		}
		if (nodes[i].lazy) {
			nodes[i].propagate(nodes[2*i], nodes[2*i+1]);
		}

		int mid = (start+end)/2;
		if (right <= mid) {
			return query_min(left, right, start, mid);
		} else if (left > mid) {
			return query_min(left, right, mid+1, end);
		} else {
			return min(
					query_min(left, mid, start, mid),
					query_min(mid+1, right, mid+1, end));
		}
	}
};

ll flow_a[N+1];
ll flow_b[N+1];
ll out[N+1];
unordered_map<int,ll> edge[N+1];

//#define DEBUG
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c;

	int n, m, q;
	cin >> n >> m >> q;

	flow_a[1] = INFLL;
	flow_b[n] = INFLL;
	for (int i = 1; i < n; i++) {
		cin >> flow_a[i+1] >> flow_b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a][b] += c;
	}

	SegTree brmq;
	brmq.build(n, flow_b);
	for (int i = 1; i <= n; i++) {
		//cerr << "compute out for " << i << endl;
		out[i] = 0;
		for (const auto& e : edge[i]) {
			ll decr = min(e.second, brmq.query_min(e.first, n));
			//cerr << "edge " << i << " -> " << e.first << " makes decr " << decr << " and gets min " << brmq.query_min(e.first, n) << endl;
			//cerr << "update from " << e.first << " to " << n << " with " << -decr << endl;
			brmq.update(e.first, n, -decr);
			out[i] += decr;
		}
		//cerr << endl;
	}
	//cerr << endl;
#ifdef DEBUG
	if (true) {
#else
	if (false) {
#endif
		cout << "OUT: ";
		for (int i = 1; i <= n; i++) {
			cout << out[i] << " ";
		}
		cout << endl;
	}

	SegTree asegtree;
	asegtree.build(n, flow_a);
	asegtree.update(n, n, -out[n]);
	for (int i = n-1; i > 0; i--) {
		out[i] += out[i+1];
		asegtree.update(i, i, -out[i]);
	}
	//cerr << endl;
#ifdef DEBUG
	if (true) {
#else
	if (false) {
#endif
		cout << "OUT, combined: ";
		for (int i = 1; i <= n; i++) {
			cout << out[i] << " ";
		}
		cout << endl;

		cout << endl;
		for (int i = 1; i <= n; i++) {
			cout << i << " is now " << asegtree.query_min(i, i) << endl;
		}
		cout << endl;
	}

	cout << out[1] + min((ll)0, asegtree.query_min(1, n)) << nl;
	while (q--) {
		cin >> a >> c;
		asegtree.replace(a+1, a+1, c - out[a+1]);
		cout << out[1] + min((ll)0, asegtree.query_min(1, n)) << nl;
	}

	return 0;
}