#include <bits/stdc++.h>
using namespace std;

struct Node {
	int sum, preff, suff;
	Node(int x = 0) {
		sum = x;
		preff = min(x, 0);
		suff = min(x, 0);
	}
	Node(Node l, Node r) {
		sum = l.sum + r.sum;
		preff = min(l.preff, l.sum + r.preff);
		suff = min(r.suff, r.sum + l.suff);
	}
};

const int N = 110;

int n, m;
int s[N], h[N], a[N], cur[N];
bool mark[N];
int life[N];

int lazy[4 * N];
Node tree[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
		lazy[x] = 0;
		tree[x] = Node(a[l]);
	} else {
		int mid = (l + r) >> 1;
		build(x + x, l, mid);
		build(x + x + 1, mid + 1, r);
		lazy[x] = 0;
		tree[x] = Node(tree[x + x], tree[x + x + 1]);
	}
}

void prop(int x, int l, int r) {
	if (lazy[x] == 0) {
		return;
	}
	tree[x] = Node(0);
	lazy[x] = 0;
	if (l != r) {
		lazy[x + x] = 1;
		lazy[x + x + 1] = 1;
	}
}

Node get(int x, int l, int r, int a, int b) {
	prop(x, l, r);
	if (r < a || l > b) return Node(0);
	if (a <= l && r <= b) {
		return tree[x];
	}
	int mid = (l + r) >> 1;
	return Node(get(x + x, l, mid, a, b), get(x + x + 1, mid + 1, r, a, b));
}

void up(int x, int l, int r, int a, int b) {
	prop(x, l, r);
	if (r < a || l > b) return;
	if (a <= l && r <= b) {
		lazy[x] = 1;
		prop(x, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	up(x + x, l, mid, a, b);
	up(x + x + 1, mid + 1, r, a, b);
	tree[x] = Node(tree[x + x], tree[x + x + 1]);
}

vector<int> solve(int pos) {
	memset(mark, 0, sizeof mark);
	build(1, 1, n);
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int id = -1;
		for (int j = 0; j < m; j++) {
			if (mark[j]) {
				continue;
			}
			int life = h[j];
			if (pos <= s[j]) {
				life += get(1, 1, n, pos, s[j]).suff;
			} else {
				life += get(1, 1, n, s[j], pos).preff;
			}
			if (life >= 0) {
				id = j;
				break;
			}
		}
		if (id == -1) {
			break;
		}
		mark[id] = 1;
		ans.push_back(id);
		if (pos <= s[id]) {
			up(1, 1, n, pos, s[id]);
		} else {
			up(1, 1, n, s[id], pos);
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		vector<int> ans = solve(i);
		if ((int) ans.size() == m) {
			cout << i << '\n';
			for (auto it : ans) {
				cout << it + 1 << ' ';
			}
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}