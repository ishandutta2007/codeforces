#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define SGN(x) (x < 0 ? -1 : x == 0 ? 0 : 1)
using namespace std;

typedef pair <int, int> pii;

struct Node {
	int x, y, c, id;
	Node() {}
	Node(int _x, int _y) {x = _x, y = _y, id = c = -1;}
	Node operator - (const Node &A) const {
		return Node(x - A.x, y - A.y);
	}
	Node operator + (const Node &A) const {
		return Node(x + A.x, y + A.y);
	}
	int operator * (const Node &A) const {
		return x * A.y - y * A.x;
	}
	bool operator < (const Node &A) const {
		return x < A.x || x == A.x && y < A.y;
	}
	bool operator == (const Node &A) const {
		return x == A.x && y == A.y;
	}
};

vector <Node> a;
vector <Node> h;
Node st[1010];
int alive[1010];
vector <pii> edge;
int n;

void get_h() {
	sort(a.begin(), a.end());
	int tp = 0;
	for (int i = 0; i < a.size(); i++) {
		Node x = a[i];
		while (tp > 1 && (st[tp - 1] - st[tp - 2]) * (x - st[tp - 2]) < 0) tp--;
		st[tp++] = x;
	}
	for (int i = 0; i < tp - 1; i++) {
		h.push_back(st[i]);
	}
	reverse(a.begin(), a.end());
	tp = 0;
	for (int i = 0; i < a.size(); i++) {
		Node x = a[i];
		while (tp > 1 && (st[tp - 1] - st[tp - 2]) * (x - st[tp - 2]) < 0) tp--;
		st[tp++] = x;
	}
	for (int i = 0; i < tp - 1; i++) {
		h.push_back(st[i]);
	}
}

int vis[1010], TOTOT = 2333;

int IN(Node x, Node y, Node z, Node P) {
	int a = (x - y) * (P - y), b = (z - x) * (P - x), c = (y - z) * (P - z);
	return abs(SGN(a) + SGN(b) + SGN(c)) == 3;
}

void solve(Node x, Node y, Node z) {
	if (x.c == z.c) swap(y, z);
	if (y.c == z.c) swap(x, z);
	TOTOT++;
	for (int i = 0; i < n; i++) {
		if (!IN(x, y, z, a[i])) continue;
		vis[i] = TOTOT;
		if (a[i].c == z.c) {
			edge.push_back(mp(a[i].id, z.id));
			solve(x, z, a[i]), solve(x, y, a[i]), solve(y, z, a[i]);
			return ;
		}
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] == TOTOT) edge.push_back(mp(a[i].id, x.id));
	}
}

int main () {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].c;
		alive[i] = 1;
		a[i].id = i;
	}
	if (n == 1 || n == 2) {
		printf("0\n");
		return 0;
	}
	get_h();
	int cnt = 0;
	for (int i = 0; i < h.size(); i++) {
		if (h[i].c != h[(i + 1) % h.size()].c) cnt++;
		alive[h[i].id] = 0;
	}
	if (cnt > 2) {
		printf("Impossible\n");
		return 0;
	}
	if (cnt == 0) {
		for (int i = 1; i < h.size(); i++) {
			edge.push_back(mp(h[i - 1].id, h[i].id));
		}
		int P = h[0].c;
		for (int i = 0; i < n; i++) {
			if (a[i].c != P) {
				for (int j = 0; j < h.size(); j++) {
					solve(a[i], h[j], h[(j + 1) % h.size()]);
				}
				goto END;
			}
		}
		for (int i = 0; i < n; i++) {
			if (alive[i]) edge.push_back(mp(h[0].id, i));
		}
	} else {
		int p = -1, q;
		for (int i = 0; i < h.size(); i++) {
			if (h[i].c == h[(i + 1) % h.size()].c) {
				edge.push_back(mp(h[i].id, h[(i + 1) % h.size()].id));
			} else {
				if (p == -1) p = (i + 1) % h.size();
				else q = (i + 1) % h.size();
			}
		}
		int cur = p;
		while (1) {
			int nxt = (cur + 1) % h.size();
			if (nxt == q) break;
			solve(h[cur], h[nxt], h[q]);
			cur = nxt;
		}
		cur = q;
		while (1) {
			int nxt = (cur + 1) % h.size();
			if (nxt == p) break;
			solve(h[cur], h[nxt], h[p]);
			cur = nxt;
		}
	}
	END:;
	cout << edge.size() << endl;
	for (int i = 0; i < edge.size(); i++) {
		cout << edge[i].fi << " " << edge[i].se << endl;
	}
	return 0;
}