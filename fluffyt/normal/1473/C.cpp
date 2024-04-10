#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int T, n, K, a[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d%d", &n, &K);
		for (int i = 1; i <= K; i++) a[i] = i;
		reverse(a + K - (n - K), a + K + 1);
		for (int i = 1; i <= K; i++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}