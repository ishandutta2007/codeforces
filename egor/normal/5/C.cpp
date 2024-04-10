#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;
const int INF = 1000000000;

char s[MAXN + 2];
int l[4 * MAXN];
int r[4 * MAXN];
int v[4 * MAXN];
int ansl, ansq;

struct Position {
	int v;
	int p;

	Position() {
		v = p = 0;
	}

	Position(int v, int p) {
		this->v = v;
		this->p = p;
	}
};

Position p[MAXN];

bool cmp(const Position &a, const Position &o) {
	if (a.v != o.v)
		return a.v < o.v;
	return a.p < o.p;
}

void read() {
	gets(s);
}

int getValue(int pl, int pr, int root) {
	if (pl >= r[root] || pr <= l[root])
		return INF;
	if (pl <= l[root] && pr >= r[root])
		return v[root];
	return min(getValue(pl, pr, 2 * root + 1), getValue(pl, pr, 2 * root + 2));
}

void setValue(int pos, int val, int root) {
	if (pos >= l[root] && pos < r[root]) {
		v[root] = min(val, v[root]);
		if (l[root] != r[root] - 1) {
			setValue(pos, val, 2 * root + 1);
			setValue(pos, val, 2 * root + 2);
		}
	}
}

void initTree(int left, int right, int root) {
	l[root] = left;
	r[root] = right;
	v[root] = INF;
	if (right != left + 1) {
		initTree(left, (left + right) / 2, 2 * root + 1);
		initTree((left + right) / 2, right, 2 * root + 2);
	}
}

void solve() {
	int n = strlen(s);
	initTree(0, n + 1, 0);
	p[0] = Position(0, 0);
	setValue(0, 0, 0);
	int q = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			q++;
		else
			q--;
		setValue(i + 1, q, 0);
		p[i + 1] = Position(q, i + 1);
	}
	sort(p, p + (n + 1), cmp);
	int cur = -1;
	ansl = 0;
	ansq = 1;
	for (int i = 0; i <= n; i++) {
		if (cur == -1 || p[cur].v != p[i].v || getValue(p[cur].p, p[i].p, 0) < p[cur].v)
			cur = i;
		else {
			int curv = p[i].p - p[cur].p;
			if (curv > ansl) {
				ansl = curv;
				ansq = 1;
			} else if (curv == ansl)
				ansq++;
		}
	}
}

void write() {
	printf("%d %d\n", ansl, ansq);
}

int main() {
	read();
	solve();
	write();
	return 0;
}