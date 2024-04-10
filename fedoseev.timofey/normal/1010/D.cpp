#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;


int res(string op, int a, int b = -1) {
	if (op == "AND") return a & b;
	if (op == "OR") return a | b;
	if (op == "XOR") return a ^ b;
	if (op == "NOT") return !a;
	assert(0);
}

struct node {
	string op;
	int u, v;
	node() {
		op = "";
		u = -1;
		v = -1;
	}
	node(string op, int u = -1, int v = -1) : op(op), u(u), v(v) {}
};

const int N = 1e6 + 7;

int val[N];
node g[N];

void dfs(int x = 0) {
	if (g[x].u != -1) dfs(g[x].u);
	if (g[x].v != -1) dfs(g[x].v);
	if (g[x].op != "IN") {
		val[x] = res(g[x].op, val[g[x].u], (g[x].v == -1 ? -1 : val[g[x].v]));
	}
}

int ch[N][2];

void dfs1(int x = 0, int p = -1) {
	if (p == -1) {
		ch[x][0] = 0;
		ch[x][1] = 1;
	}
	else {
		int a = g[p].u;
		int b = g[p].v;
		if (b == x) swap(a, b);
		ch[x][0] = ch[p][res(g[p].op, 0, (b == -1 ? -1 : val[b]))];
		ch[x][1] = ch[p][res(g[p].op, 1, (b == -1 ? -1 : val[b]))];
	}
	if (g[x].u != -1) dfs1(g[x].u, x);
	if (g[x].v != -1) dfs1(g[x].v, x);
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "NOT") {
			int u;
			cin >> u;
			--u;
			g[i] = node(s, u);
		}
		else if (s == "IN") {
			int u;
			cin >> u;
			g[i] = node(s);
			val[i] = u;
		}
		else {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[i] = node(s, u, v);
		}
	}
	dfs();
	dfs1();
	for (int i = 0; i < n; ++i) {
		if (g[i].op == "IN") {
			cout << ch[i][val[i] ^ 1];
		}
	}
}