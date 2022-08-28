#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 100010, P = 1e9 + 7;

int n, m, cnt0 = 1;
int a[N], ans[N];
int bas[20], cnt[20];

vector<pair<int, int> > qry[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) {
		int l, x;
		scanf("%d%d", &l, &x);
		qry[l].emplace_back(x, i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 19; j >= 0; --j) {
			if ((a[i] >> j) & 1) {
				if (!bas[j]) {
					bas[j] = a[i];
					cnt[j] = 1;
					break;
				} else
					a[i] ^= bas[j];
			}
		}
		if (a[i] == 0) {
			cnt0 <<= 1;
			if (cnt0 >= P)
				cnt0 -= P;
		}
		for (pair<int, int> q : qry[i]) {
			int as = 1;
			for (int j = 19; j >= 0; --j)
				if ((q.first >> j) & 1) {
					q.first ^= bas[j];
					as *= cnt[j];
				}
			ans[q.second] = as * cnt0;
		}
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}