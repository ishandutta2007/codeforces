#include <cstdio>
#include <cstring>

#ifndef ONLINE_JUDGE
#include <ctime>
#endif

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

int n, pc;
ui ans;
ui a, b, c, d;

int pr[18000];
bool vis[10000010];

ui f(ui p) { return d + p * (c + p * (b + p * a)); }

ui count(int p) {
	ui ret = 0;
	int cur = n;
	while (cur /= p)
		ret += cur;
	return ret;
}

void sieve(int l, int r) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= pc; ++i)
		for (int x = (l + pr[i] - 1) / pr[i] * pr[i]; x <= r; x += pr[i])
			vis[x - l] = true;
	for (int x = l; x <= r; ++x)
		if (!vis[x - l] && x != 1) {
			ans += f(x) * count(x);
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%u%u%u%u", &n, &a, &b, &c, &d);
	int rt = 1;
	while (rt * rt < n)
		++rt;
	for (int x = 2; x <= rt; ++x) {
		if (!vis[x]) {
			pr[++pc] = x;
			ans += count(x) * f(x);
			for (int y = x; y <= rt; y += x)
				vis[y] = true;
		}
	}
	int lft = 1;
	for (; lft + 9999999 <= n; lft += 10000000)
		sieve(lft, lft + 9999999);
	if (lft <= n)
		sieve(lft, n);

	printf("%u\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}