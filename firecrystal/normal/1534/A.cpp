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

const int N = 55;

int n, m, c;

char g[N][N];

bool inline check() {
	bool o = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch = ((i + j) & 1) ? 'R' : 'W';
			if (g[i][j] != '.' && g[i][j] != ch) {
				o = 0;
			}
		}
	}
	if (o) {
		puts("YES");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char ch = ((i + j) & 1) ? 'R' : 'W';
				putchar(ch);
			}
			puts("");
		}
		return 1;
	}
	o = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch = ((i + j + 1) & 1) ? 'R' : 'W';
			if (g[i][j] != '.' && g[i][j] != ch) {
				o = 0;
			}
		}
	}
	if (o) {
		puts("YES");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char ch = ((i + j + 1) & 1) ? 'R' : 'W';
				putchar(ch);
			}
			puts("");
		}
		return 1;
	}
	return 0;
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", g[i] + 1);
		}
		if (!check()) puts("NO");
	}
	return 0;
}