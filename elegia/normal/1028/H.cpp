#include <cstdio>

#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int X = 5100000, N = 200000, Q = 1100000;

int a[N];
int ans[Q];
int pr[X], cnt[X];
int sv[X][8];
int help[15];

vector<pair<int, int> > qry[N];

int main() {
	for (int x = 2; x < X; ++x) {
		if (!cnt[x]) {
			for (int y = x; y < X; y += x) {
				cnt[y] = cnt[y / x] + 1;
				pr[y] = x;
			}
		}
	}
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int x = a[i];
		while (x != 1) {
			int p = pr[x];
			while (a[i] % p == 0 && a[i] / p % p == 0) {
				a[i] /= p * p;
				x /= p * p;
			}
			if (a[i] % p == 0)
				x /= p;
		}
	}
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		qry[l].emplace_back(r, i);
	}
	fill(*sv, sv[X - 1] + 8, n + 1);
	fill(help, help + 15, n + 1);
	for (int i = n; i; --i) {
		for (int x = 1; x * x <= a[i]; ++x)
			if (a[i] % x == 0) {
				for (int j = 0; j <= 7; ++j)
					help[j + cnt[a[i]] - cnt[x]] = min(help[j + cnt[a[i]] - cnt[x]], sv[x][j]);
				int y = a[i] / x;
				for (int j = 0; j <= 7; ++j)
					help[j + cnt[a[i]] - cnt[y]] = min(help[j + cnt[a[i]] - cnt[y]], sv[y][j]);
			}
		for (const auto& qr : qry[i]) {
			while (help[ans[qr.second]] > qr.first)
				++ans[qr.second];
		}
		for (int x = 1; x * x <= a[i]; ++x)
			if (a[i] % x == 0) {
				sv[x][cnt[a[i]] - cnt[x]] = i;
				sv[a[i] / x][cnt[x]] = i;
			}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}