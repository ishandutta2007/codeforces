#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1000010;

int n;
int fst[26], lst[26], sum[N];
char s[N];

int main() {
	int k;
	scanf("%d%d%s", &n, &k, s + 1);
	for (int i = 1; i <= n; ++i) {
		if (!fst[s[i] - 'A'])
			fst[s[i] - 'A'] = i;
		lst[s[i] - 'A'] = i;
	}
	for (int i = 0; i < 26; ++i) {
		++sum[fst[i]];
		--sum[lst[i] + 1];
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] += sum[i - 1];
		if (sum[i] > k) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}