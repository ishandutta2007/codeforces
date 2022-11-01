// Skyqwq
#include <iostream>
#include <cstdio>

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
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 4e5 + 5, P = 1e9 + 7;

int n, f[N], sz[N], p[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	f[x] = y, sz[y] += sz[x];
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) {
			f[i] = i, sz[i] = 1;
			read(p[i]);
		}
		for (int i = 1, x; i <= n; i++) {
			read(x);
			merge(p[i], x);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (i == find(i)) cnt++;
		int s = 1;
		for (int i = 1; i <= cnt; i++)
			s = s * 2 % P;
		printf("%d\n", s);
	}
	return 0;
}