#include <cstdio>

#include <algorithm>

using namespace std;


const int N = 120;


int n, m;

char s[120];

int main() {
	scanf("%d%d", &n, &m);
	int l = n, r = 1, u = 1, d = m;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j)
			if (s[j] == 'B') {
				l = min(l, i);
				r = max(r, i);
				u = max(u, j);
				d = min(d, j);
			}
	}
	printf("%d %d\n", (l + r) / 2, (d + u) / 2);
	return 0;
}