#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 1005;
int T;
char a[MAXN], b[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%s%s", a + 1, b + 1);
		int n = strlen(a + 1), m = strlen(b + 1);
		int l = n * m / __gcd(n, m);
		for (int i = n; i < l; i += n)
		for (int j = 1; j <= n; j++) a[i + j] = a[j];
		for (int i = m; i < l; i += m)
		for (int j = 1; j <= m; j++) b[i + j] = b[j];
		int f = 1;
		for (int i = 1; i <= l; i++)
			if (a[i] != b[i]) { f = 0; break; }
		if (f) {
			for (int i = 1; i <= l; i++) putchar(a[i]);
			putchar('\n');
		} else puts("-1");
	}
	return 0;
}