#include<bits/stdc++.h>
//#define DEBUG
using namespace std;
using LL = long long;

random_device rds;
const int seed = rds();
mt19937 rd(seed);

int n, ch;
void init() {
#ifdef DEBUG
	n = rd() % 10 + 1;
	ch = rd() % n + 1;
#else
	cin >> n;
#endif
}

bool querybit(int b) {
#ifdef DEBUG
	static int lstAns = 1;
	int mask = 0;
	if (lstAns == 1) {
		if (rd() % 100 <= 90) {
			mask = 1;
		} else {
			mask = 0;
		}
	}
	lstAns = (mask ^ 1);
	return ((ch >> b) & 1) ^ mask;
#else
	vector<int> q;
	for (int i = 1; i <= n; i++) {
		if (i & (1 << b)) {
			q.emplace_back(i);
		}
	}
	if (q.size() == 0) {
		return false;
	}
	cout << "? " << q.size() << ' ';
	for (auto v : q) {
		cout << v << ' ';
	}
	cout << '\n';
	cout.flush();
	string s;
	cin >> s;
	return (s[0] == 'Y');
#endif
}

bool answer(int num) {
#ifdef DEBUG
	return ch == num;
#else
	if (num <= 0 || num > n) {
		return false;
	}
	cout << "! " << num << '\n';
	cout.flush();
	string s;
	cin >> s;
	return s[1] == ')';
#endif
}

struct DSU {
	vector<int> fa;
	DSU(int n) : fa(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
		}
	}
	int getfa(int v) {
		return (fa[v] == v) ? v : (fa[v] = getfa(fa[v]));
	}
	bool merge(int u, int v) {
		u = getfa(u), v = getfa(v);
		if (u == v) {
			return false;
		}
		fa[u] = v;
		return true;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	init();
	int b = 0, pcnt = 0;
	for (int i = n; i > 0; i >>= 1, ++b);
	set<int> qr;
	vector<array<int, 2>> pt(b);
	for (int i = 0; i < b; i++) {
		qr.insert(i);
		pt[i][0] = ++pcnt;
		pt[i][1] = ++pcnt;
	}
	int yes = ++pcnt;
	DSU dsu(pcnt);
	while (qr.size() >= 2) {
		int x = *qr.begin();
		qr.erase(x);
		int y = *qr.begin();
		qr.erase(y);
		int x0 = querybit(x), y0 = querybit(y), y1 = querybit(y), x1 = querybit(x);
		if (y0 == y1) {
			dsu.merge(pt[y][y0], yes);
			qr.insert(x);
		} else {
			if (x0 == x1) {
				dsu.merge(pt[x][x0], yes);
				qr.insert(y);
			} else {
				dsu.merge(pt[x][x0], pt[y][y1]);
				dsu.merge(pt[x][x1], pt[y][y0]);
				qr.insert(y);
			}
		}
	}
	int res = *qr.begin();
	for (int d = 0; d < 2; d++) {
		int val = 0;
		for (int i = 0; i < b; i++) {
			if (dsu.getfa(pt[i][1]) == dsu.getfa(pt[res][d]) || dsu.getfa(pt[i][1]) == dsu.getfa(yes)) {
				val ^= (1 << i);
			}
		}
		if (answer(val)) {
			return 0;
		}
	}
	assert(false);
    return 0;
}