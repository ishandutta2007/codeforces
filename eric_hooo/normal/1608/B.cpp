#include <bits/stdc++.h>
using namespace std;

vector <int> p;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		if (a + b > n - 2) {
			printf("-1\n");
			continue;
		}
		if (abs(a - b) > 1) {
			printf("-1\n");
			continue;
		}
		p.clear();
		if (a == b) {
			int l = 1, r = n;
			p.push_back(r--);
			for (int i = 0; i < b; i++) {
				p.push_back(l++), p.push_back(r--);
			}
			while (l <= r) p.push_back(r--);
		} else {
			int flag = 0;
			if (b + 1 == a) swap(a, b), flag = 1;
			int l = 1, r = b * 2 + 1;
			p.push_back(r--);
			for (int i = 0; i < b; i++) {
				p.push_back(l++), p.push_back(r--);
			}
			for (int i = b * 2 + 2; i <= n; i++) {
				p.push_back(i);
			}
			if (flag) {
				for (auto &it : p) {
					it = n - it + 1;
				}
			}
		}
		for (auto it : p) {
			printf("%d ", it);
		}
		printf("\n");
	}
	return 0;
}