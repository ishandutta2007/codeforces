#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200005, M = 200005;
typedef long long LL;
int n, m, p[M], cnt[N], sum[N][26];
LL ans[26];
char s[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &m, s + 1);
		for (int i = 0; i < 26; i++) ans[i] = 0;
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		cnt[n] = 1;
		for (int i = 1; i <= m; i++) scanf("%d", p + i), cnt[p[i]]++;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
			sum[i][s[i] - 'a']++;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				ans[j] += (LL)sum[i][j] * cnt[i];
			}
		}
		for (int i = 0; i < 26; i++) printf("%lld ", ans[i]);
		puts("");
	}
	return 0;
}