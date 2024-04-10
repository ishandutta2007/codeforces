#include <cstdio>
#include <numeric>
#include <cstring>

using namespace std;

const int N = 22;

int n, m, cc;

int f[1 << N], a[1 << N], had[1 << N], d[1 << N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void create(int x);
void merge(int x, int y);

void dfs(int s, int x);

int main() {
	scanf("%d%d", &n, &m);
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		create(a[i]);
		had[a[i]] = true;
	}
	for (int i = 0; i < n; ++i)
		for (int s = 0; s < (1 << n); ++s)
			if ((s >> i) & 1)
				had[s] |= had[s ^ (1 << i)];
	for (int i = 1; i <= m; ++i)
		dfs(a[i] ^ ((1 << n) - 1), a[i]);
	printf("%d\n", cc);
	return 0;
}

void create(int x) {
	f[x] = x;
	++cc;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		--cc;
		f[x] = y;
	}
}

void dfs(int s, int x) {
	if (d[s]) {
		merge(s, x);
		return;
	}
	if (!had[s])
		return;
	if (f[s] == -1)
		create(s);
	d[s] = true;
	merge(s, x);
	for (int i = 0; i < n; ++i)
		if ((s >> i) & 1)
			dfs(s ^ (1 << i), s);
}