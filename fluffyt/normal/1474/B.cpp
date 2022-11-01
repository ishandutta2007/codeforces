#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
bool vis[MAXN];

int main() {
	for (int i = 2; i <= 100000; i++)
	for (int j = i + i; j <= 100000; j += i) vis[j] = 1;
	int T; scanf("%d", &T);
	while (T--) {
		int d; scanf("%d", &d);
		int a = d + 1;
		while (vis[a]) ++a;
		int b = a + d;
		while (vis[b]) ++b;
		printf("%d\n", a * b);
	}
	return 0;
}