#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 5005;
int Q;

int main() {
	scanf("%d", &Q);
	while (Q--) {
		int u, v; scanf("%d%d", &u, &v);
		if (u > v) {
			puts("NO");
			continue;
		}
		if (__builtin_popcount(u) < __builtin_popcount(v)) {
			puts("NO");
			continue;
		}
		vector<int> a, b;
		for (int i = 0; i < 30; i++) if (u >> i & 1) a.push_back(i);
		for (int i = 0; i < 30; i++) if (v >> i & 1) b.push_back(i);
		bool f = true;
		for (int i = 0; i < (int)b.size(); i++) {
			if (a[i] > b[i]) {
				f = false;
				break;
			}
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}