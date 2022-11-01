#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int T, n;
char b[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		scanf("%s", b + 1);
		int lst = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] - '0' + 1 == lst) {
				putchar('0');
				lst = b[i] - '0';
			} else {
				putchar('1');
				lst = b[i] - '0' + 1;
			}
		}
		putchar('\n');
	}
	return 0;
}