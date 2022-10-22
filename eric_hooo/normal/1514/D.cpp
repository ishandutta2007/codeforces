#include <bits/stdc++.h>
#define rnd() (rand() << 15 | rand())
using namespace std;

int a[300010];
vector <int> all[300010];

int GetNum(int x, int l, int r) {
	return upper_bound(all[x].begin(), all[x].end(), r) - lower_bound(all[x].begin(), all[x].end(), l);
}

int main() {
	srand((int)time(NULL)), rnd(), rnd(), rnd();
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), all[a[i]].push_back(i);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		int lim = (r - l + 2) / 2, len = r - l + 1;
		for (int it = 0; it < 30; it++) {
			int x = a[rnd() % (r - l + 1) + l], cnt = GetNum(x, l, r);
			if (cnt > lim) {
				cnt -= lim;
				if (len % 2 == 0) printf("%d\n", cnt * 2);
				else printf("%d\n", cnt * 2 + 1);
				goto END;
			}
		}
		printf("1\n");
		END:;
	}
	return 0;
}