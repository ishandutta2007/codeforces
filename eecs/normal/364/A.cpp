#include <bits/stdc++.h>
using namespace std;

int a;
char s[4010];
map<int, int> cnt;

int main() {
	scanf("%d %s", &a, s + 1);
	int n = strlen(s + 1), all = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i, k = 0; j <= n; j++) {
			k += s[j] - '0', cnt[k]++, all++;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i, k = 0; j <= n; j++) {
			k += s[j] - '0';
			if (!k) {
				if (!a) ans += all;
			} else if (!(a % k)) {
				ans += cnt[a / k];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}