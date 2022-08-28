#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;
const int P = 1000000007;

int n;
char s[N];
int fr[N], ifr[N], inv[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int pre = 0, suf = count(s + 1, s + n + 1, ')');
	inv[1] = 1;
	for (int x = 2; x <= n; ++x)
		inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
	fr[0] = 1;
	ifr[0] = 1;
	for (int x = 1; x <= n; ++x) {
		fr[x] = fr[x - 1] * (ll)x % P;
		ifr[x] = ifr[x - 1] * (ll)inv[x] % P;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') {
			ans = (ans + fr[pre + suf] * (ll)ifr[pre + 1] % P * ifr[suf - 1]) % P;
			++pre;
		} else
			--suf;
	}
	printf("%d\n", ans);
	return 0;
}