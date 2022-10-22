#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

set <pii> S;
multiset <pii> R;
int X[500010];
int T[500010];
int C[500010];
long long A[500010];
int id[500010];

bool cmp(int x, int y) {
	return X[x] < X[y];
}

char buf[10000000], *EN = buf + 10000000, *CU = EN;

char getc() {
	if (CU == EN) fread(buf, 1, 10000000, stdin), CU = buf;
	CU++;
	return *(CU - 1);
}

void read(int &x) {
	char c = getc();
	while (c < '0' || c > '9') c = getc();
	x = c - '0', c = getc();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getc();
}

char st[1000]; int tp;

void print(long long x) {
	tp = 0;
	if (!x) st[tp++] = '0';
	while (x) st[tp++] = x % 10 + '0', x /= 10;
	while (tp--) putchar(st[tp]);
}

int main () {
	int n, m; read(n), read(m);
	for (int i = 0; i < n; i++) {
		read(X[i]), read(T[i]);
		C[i] = 0, A[i] = T[i];
		id[i] = i;
	}
	sort(id, id + n, cmp);
	int maxj = -1;
	for (int i = 0; i < n; i++) {
		int x = X[id[i]], t = T[id[i]];
		if (maxj < x + t) S.insert(mp(x + t, id[i])), maxj = x + t;
	}
	for (int i = 0; i < m; i++) {
		int p, b; read(p), read(b);
		set <pii> :: iterator it = S.lower_bound(mp(p, -1));
		if (it == S.end()) {
			R.insert(mp(p, b));
			continue;
		}
		int x = it->se;
		if (X[x] > p) {
			R.insert(mp(p, b));
			continue;
		}
		T[x] = min(T[x] + b, INF), C[x]++, A[x] += b;
		set <pii> :: iterator pos = R.lower_bound(mp(X[x], -1));
		while (pos != R.end() && pos->fi <= X[x] + T[x]) {
			T[x] = min(T[x] + pos->se, INF), C[x]++, A[x] += pos->se;
			pos = R.erase(pos);
		}
		while (it != S.end() && it->fi <= X[x] + T[x]) {
			it = S.erase(it);
		}
		S.insert(mp(X[x] + T[x], x));
	}
	for (int i = 0; i < n; i++) {
		print(C[i]), putchar(' '), print(A[i]), putchar('\n');
	}
	return 0;
}
/*
4 6
10 2
15 0
6 1
0 1
110 10
1 1
6 0
15 10
14 100
12 2

1 2
10 2
20 2
12 1

*/