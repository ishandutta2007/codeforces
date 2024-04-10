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

const int N = 2e5 + 5;

int n, a[N], b[N];

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1);
		int o = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0') o++;
		if (o % 2 == 1) {
			puts("NO"); continue;
		}
		int tot = 0, c = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				if (tot * 2 + o < n) a[i] = 1, tot++;
				else a[i] = 0;
				b[i] = a[i];
			} else {
				a[i] = c;
				c ^= 1;
				b[i] = a[i] ^ 1;
			}
			//cout << a[i];
		}
		//puts("");
		bool ok = true;
		int top = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i]) top++;
			else {
				if (!top) {
					ok = false;
					break;
				}
				top--;
			}
		}
		if (top) ok = false;
		top = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i]) top++;
			else {
				if (!top) {
					ok = false;
					break;
				}
				top--;
			}
		}
		if (top) ok = false;
		if (!ok) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n; i++) putchar((a[i]) ? '(' : ')');
			puts("");
			for (int i = 1; i <= n; i++) putchar(b[i] ? '(' : ')');
			puts("");
		}
	}
	return 0;
}