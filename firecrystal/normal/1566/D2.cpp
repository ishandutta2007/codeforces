// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 305;

int n, m, a[N * N], p[N * N], s[N * N];

bool inline cmp(int x, int y) {
	if (a[x] == a[y]) return x > y;
	return a[x] < a[y];
} 

void inline fill(int l, int r, int x, int y) {
	for (int i = 0; i <= r - l; i++) {
		s[i + l] = p[x + i];
	}
}

int inline g(int x) {
	return (x + m - 1) / m;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n * m; i++) read(a[i]), p[i] = i;
		int ans = 0;
		sort(p + 1, p + 1 + n * m, cmp);
		for (int i = 1; i <= n * m; i++) {
			int j = i;
			while (j < n * m && a[p[j + 1]] == a[p[i]]) ++j;
			int x = g(i), y = g(j);
			if (x == y) {
				fill(i, j, i, j);
			} else {
				int c1 = x * m - i + 1;
				int c2 = j - (y - 1) * m;
				fill(i, i + c1 - 1, j - c1 + 1, j);
				fill(j - c2 + 1, j, i, i + c2 - 1);
				fill(i + c1, j - c2, i + c2, j - c1);
			}
			i = j;
		}
		for (int i = 1; i <= n; i++) {
			int u = (i - 1) * m;
			for (int j = 1; j <= m; j++) {
				for (int k = j + 1; k <= m; k++) {
					if (s[u + j] < s[u + k]) ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}