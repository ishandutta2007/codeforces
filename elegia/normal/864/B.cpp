#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

#define LOG(FMT) fprintf(stderr, FMT...)

using namespace std;

const int N = 210;

int n, sum, ans;
char s[N];
bool f[26];

int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			memset(f, 0, sizeof(f));
			sum = 0;
			continue;
		}
		if (!f[s[i] - 'a']) {
			f[s[i] - 'a'] = true;
			++sum;
			ans = max(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}