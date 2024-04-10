#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

char s[2010], t[2010], cp[2010];

int n;
int cnt[26];

void shift(int x);

int main() {
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < n; ++i)
		++cnt[s[i] - 'a'];
	for (int i = 0; i < n; ++i)
		--cnt[t[i] - 'a'];
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] != 0) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", n * 3);
	for (int i = n - 1; i >= 0; --i) {
		int x;
		for (x = 1; s[n - x] != t[i]; ++x);
		printf("%d %d %d ", n, n - x, 1);
		shift(n);
		shift(n - x);
		shift(1);
	}
	return 0;
}

void shift(int x) {
	for (int i = 0; i < n - x; ++i)
		cp[i + x] = s[i];
	for (int i = 0; i < x; ++i)
		cp[i] = s[n - i - 1];
	strcpy(s, cp);
}