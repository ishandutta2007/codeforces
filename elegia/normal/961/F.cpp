#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1000010;
const int P = 1e9 + 7;

int n;
int ans[N];
char s[N];
int pw[N], hsh[N];

int subHash(int lst, int len);

int main() {
	scanf("%d%s", &n, s + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = pw[i - 1] * 26LL % P;
		hsh[i] = (hsh[i - 1] * 26LL + (s[i] - 'a')) % P;
	}
	int cur = -1;
	for (int i = (n + 1) / 2; i; --i) {
		cur += 2;
		if (i * 2 == n + 1)
			cur = -1;
		while (cur != -1 && subHash(i + cur - 1, cur) != subHash(n - i + 1, cur))
			cur -= 2;
		ans[i] = cur;
	}
	for (int i = 1; i <= (n + 1) / 2; ++i)
		printf("%d ", ans[i]);
	return 0;
}

int subHash(int lst, int len) {
	int ret = (hsh[lst] - hsh[lst - len] * (ll)pw[len]) % P;
	if (ret < 0)
		ret += P;
	return ret;
}