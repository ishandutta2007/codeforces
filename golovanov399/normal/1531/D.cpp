#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const vector<string> colors = {"", "red", "orange", "yellow", "green", "blue", "indigo", "violet"};
const vector<string> locks = {"", "lock", "unlock"};

int get_color(const string& s) {
	return find(all(colors), s) - colors.begin();
}

int get_lock(const string& s) {
	return find(all(locks), s) - locks.begin();
}

struct Node {
	int color[2];
	int lock;
};

Node merge(const Node& a, const Node& b) {
	return {
		{
			a.lock ? (b.color[a.lock - 1] ? b.color[a.lock - 1] : a.color[0]) : (b.color[0] ? b.color[0] : a.color[0]),
			a.lock ? (b.color[a.lock - 1] ? b.color[a.lock - 1] : a.color[1]) : (b.color[1] ? b.color[1] : a.color[1]),
		},
		b.lock ? b.lock : a.lock
	};
}

Node singleton(const string& s) {
	if (int c = get_color(s); c == (int)colors.size()) {
		int l = get_lock(s);
		return {{0, 0}, l};
	} else {
		return {{0, c}, 0};
	}
}

const Node def = {{0, 0}, 0};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(const vector<string>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n, def);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = singleton(ar[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	void change(int pos, const string& s) {
		int v = pos + n;
		a[v] = singleton(s);
		while (v > 1) {
			v /= 2;
			a[v] = merge(a[v + v], a[v + v + 1]);
		}
	}

	int getcolor() const {
		int c = a[1].color[1];
		if (c == 0) {
			c = 5;
		}
		return c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegTree tree(a);

	cout << colors[tree.getcolor()] << "\n";
	int q = nxt();
	while (q --> 0) {
		int pos = nxt() - 1;
		string s;
		cin >> s;
		tree.change(pos, s);
		cout << colors[tree.getcolor()] << "\n";
	}

	return 0;
}