#include <bits/stdc++.h>
using namespace std;

int a[200010];
vector <int> all[200010];
vector <int> pos[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			pos[i].clear();
			all[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			pos[a[i]].push_back(i);
		}
		int M = 0;
		for (int i = 1; i <= n; i++) {
			M = max(M, (int)pos[i].size());
			for (int j = 0; j < pos[i].size(); j++) {
				all[j].push_back(pos[i][j]);
			}
		}
		for (int j = 0; j < M; j++) {
			for (int i = 0; i + 1 < all[j].size(); i++) {
				swap(a[all[j][i]], a[all[j][i + 1]]);
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}