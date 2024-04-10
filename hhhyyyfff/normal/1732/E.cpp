#include <bits/stdc++.h>

using namespace std;
#define N 50001
#define S 100
#define T 500

vector<int> fct[N];
int mp[T][N];
int n, q, a[N], b[N], tag[T], t, l, r, x;
long long block[T], sig[N], pre[T][N];

int rd(int x = 50000) {
	return (rand() * RAND_MAX + rand()) % x + 1;
}

long long sqr(long long x) { return x * x; }
long long& calc(int x) {
	return sig[x] = (long long)a[x] * b[x] / sqr(__gcd(a[x], b[x]));
}

void pushup(int i) {
	block[i] = LLONG_MAX;
	for (int j = i * S + 1; j <= i * S + S; ++j)
		block[i] = min(block[i], sig[j]);
}

void upd(int x, int v) {
	int id = (x - 1) / S;
	if (tag[id]) {
		for (int i = id * S + 1; i <= id * S + S; ++i) {
			a[i] = tag[id];
			calc(i);
		}
		tag[id] = 0;
	}
	a[x] = v;
	calc(x);
}

long long qry(int x) {
	if (tag[(x - 1) / S]) {
		a[x] = tag[(x - 1) / S];
		return calc(x);
	}
	return sig[x];
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	fill(b + n + 1, b + N, 1);
	n = N - 1;
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			fct[j].push_back(i);
	for (int i = 1; i < N; ++i) {
		calc(i);
		for (int j : fct[b[i]]) {
			int& tmp = mp[(i - 1) / S][j];
			if (!tmp) tmp = b[i] / j; else tmp = min(tmp, b[i] / j);
		}
	}
	for (int i = 0; i < T; ++i) {
		pushup(i);
		for (int j = 1; j < N; ++j) pre[i][j] = LLONG_MAX;
		for (int j = 1; j < N; ++j)
			if (mp[i][j])
			    for (int k = j; k < N; k += j)
					pre[i][k] = min(pre[i][k], (long long)k / j * mp[i][j]);
	}
	while (q--) {
		scanf("%d%d%d", &t, &l, &r);
		int bg = (l - 1) / S, ed = (r - 1) / S;
		if (t == 1) {
			scanf("%d", &x);
			if (bg == ed) {
				for (int i = l; i <= r; ++i) upd(i, x);
				pushup(bg);
			} else {
				for (int i = l; i <= bg * S + S; ++i) upd(i, x);
				for (int i = ed * S + 1; i <= r; ++i) upd(i, x);
				pushup(bg);
				pushup(ed);
				for (int i = bg + 1; i < ed; ++i) {
					tag[i] = x;
					block[i] = pre[i][x];
				}
			}
		} else {
			long long ans = LLONG_MAX;
			if (bg == ed) {
				for (int i = l; i <= r; ++i) ans = min(ans, qry(i));
			} else {
				for (int i = l; i <= bg * S + S; ++i) ans = min(ans, qry(i));
				for (int i = ed * S + 1; i <= r; ++i) ans = min(ans, qry(i));
				for (int i = bg + 1; i < ed; ++i) ans = min(ans, block[i]);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}