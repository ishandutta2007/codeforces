#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <string> a;
char buf[1000010];
int sum[1000010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf), a.push_back(buf);
	}
	for (int j = 1; j < m; j++) {
		for (int i = 0; i + 1 < n; i++) {
			if (a[i][j] == 'X' && a[i + 1][j - 1] == 'X') sum[j] = 1;
		}
		sum[j] += sum[j - 1];
	}
	int q; scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		l--, r--;
		if (sum[r] != sum[l]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}