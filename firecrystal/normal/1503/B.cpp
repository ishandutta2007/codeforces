// Skyqwq
#include <iostream>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
 
// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
 
void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}
 
void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 105;
 
int n, a, c[4];
 
void inline out(int b, int i, int j) {
	printf("%d %d %d\n", b, i, j);
	fflush(stdout);
}
 
bool vis[N][N];
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[(i + j) % 2 + 1]++;
		}
	}
	for (int k = 1; k <= n * n; k++) {
		scanf("%d", &a);
		if (a <= 2 && c[3 - a] == 0) {
			bool ok = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (!vis[i][j]) {
						vis[i][j] = 1;
						out(3, i, j);
						c[(i + j) % 2 + 1]--;
						ok = true; break;
					}
				}
				if (ok) break;
			}
		} else {
			bool ok = false;
			int b = 1;
			if (a == 1 || c[b] == 0) b = 2;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (!vis[i][j] && (i + j) % 2 + 1 == b) {
						vis[i][j] = 1;
						out(b, i, j);
						c[b]--;
						ok = true; break;
					}
				}
				if (ok) break;
			}
		}
	}
	return 0;
}