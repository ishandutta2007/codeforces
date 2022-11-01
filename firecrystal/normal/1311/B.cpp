#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n, m, a[N], p[N];
bool check() {
    for (int i = 1; i < n; i++) if (a[i + 1] < a[i]) return false;
    return true;
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= m; i++) scanf("%d", p + i);
		sort(p + 1, p + 1 + m);
		for (int i = 1; i <= m; i++) {
			int j = i;
			while (j < m && p[j + 1] == p[j] + 1) j++;
			// r = j + 1
			int l = p[i], r = p[j] + 1;
			sort(a + l, a + 1 + r);
			i = j;
		}
		puts(check() ? "YES" : "NO");
	}
	return 0;
}