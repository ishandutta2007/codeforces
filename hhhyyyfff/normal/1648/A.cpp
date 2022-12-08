#include <bits/stdc++.h>

using namespace std;

vector<int> line[100001], col[100001];
int n, m, c, l;
long long ans, sum;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &c);
			line[c].push_back(i);
			col[c].push_back(j);
		}
	for (int i = 1; i <= 100000; ++i) {
		sort(line[i].begin(), line[i].end());
		sum = 0;
		l = line[i].size();
		for (int j = 0; j < l; ++j) {
			ans += (long long)line[i][j] * j - sum;
			sum += line[i][j];
		}
	}
	for (int i = 1; i <= 100000; ++i) {
		sort(col[i].begin(), col[i].end());
		sum = 0;
		l = col[i].size();
		for (int j = 0; j < l; ++j) {
			ans += (long long)col[i][j] * j - sum;
			sum += col[i][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}