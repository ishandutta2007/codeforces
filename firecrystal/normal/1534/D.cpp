// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
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

void inline ask(int x) {
	printf("? %d\n", x);
	fflush(stdout);
}

const int N = 2e3 + 5;

int n, d[N], A[N], B[N], t, c[2];
 
vector<int> g[N];

int main() {
	read(n);
	ask(1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i), g[d[i]].pb(i);
		if (d[i] == 1) {
			++t;
			A[t] = 1, B[t] = i;
		}
		if (i > 1) c[d[i] & 1]++;
	}
	int o = c[0] > c[1] ? 1 : 2;
	for (int i = o; i <= n; i += 2) {
		for (int v: g[i]) {
			ask(v);
			for (int j = 1; j <= n; j++) {
				int x; scanf("%d", &x);
				if (x == 1 && j > 1) {
					++t;
					A[t] = v, B[t] = j;
				}
			}
		}
	}
	puts("!");
	for (int i = 1; i <= t; i++)
		printf("%d %d\n", A[i], B[i]);
	fflush(stdout);
	return 0;
}