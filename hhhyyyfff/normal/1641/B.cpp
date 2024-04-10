#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
int T, n, fst, a[500], q, p[250000], c[250000], d, t[500];
bool ns;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		mp.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			++mp[a[i]];
		}
		ns = 0;
		for (auto i : mp)
			if (i.second & 1) {
				puts("-1");
				ns = 1;
				break;
			}
		if (ns) continue;
		fst = 0;
		q = d = 0;
		while (n) {
			for (int i = 1; i < n; ++i)
				if (a[i] == a[0]) {
					for (int j = 1; j < i; ++j) {
						p[q] = fst + i + j;
						c[q++] = a[j];
					}
					fst += t[d++] = i * 2;
					for (int j = 1; j < i - j; ++j) swap(a[j], a[i - j]);
					for (int j = 0; j < i; ++j) a[j] = a[j + 1];
					for (int j = i - 1; j + 2 < n; ++j) a[j] = a[j + 2];
					n -= 2;
					break;
				}
		}
		printf("%d\n", q);
		for (int i = 0; i < q; ++i) printf("%d %d\n", p[i], c[i]);
		printf("%d\n%d", d, t[0]);
		for (int i = 1; i < d; ++i) printf(" %d", t[i]);
		puts("");
	}
	return 0;
}