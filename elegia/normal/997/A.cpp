#include <cstdio>
#include <cstring>

#include <algorithm>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 300010;

int n, x, y, cnt;
ll ans;
char s[N];

int main() {
	scanf("%d%d%d%s", &n, &x, &y, s + 1);
	s[0] = '1';
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0' && s[i - 1] == '1')
			++cnt;
	if (cnt == 0)
		puts("0");
	else {
		if (x < y) {
			ans = (cnt - 1) * (ll)x + y;
		} else
			ans = cnt * (ll)y;
		printf("%lld\n", ans);
	}
	return 0;
}