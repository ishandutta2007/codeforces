#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];
vector<int> V[2500010];
vector<pair<int, int>> cand[5000010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		V[a[i]].push_back(i);
	}
	for (int i = 1; i <= 2500000; i++) if (V[i].size() > 3) {
		puts("YES");
		printf("%d %d %d %d\n", V[i][0], V[i][1], V[i][2], V[i][3]), exit(0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (auto p : cand[a[i] + a[j]]) {
				if (p.first ^ i && p.second ^ i && p.first ^ j && p.second ^ j) {
					puts("YES");
					printf("%d %d %d %d\n", i, j, p.first, p.second), exit(0);
				}
			}
			cand[a[i] + a[j]].emplace_back(i, j);
		}
	}
	puts("NO");
	return 0;
}