#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
multiset <int> S;
vector <int> dp;
int len[100010];
int n, m;

int GetNum(int l, int r) {return l > r ? 0 : upper_bound(b, b + m, r) - lower_bound(b, b + m, l);}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[0] = 0, a[n + 1] = 0x3f3f3f3f;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]), S.insert(b[i]);
	sort(b, b + m), m = unique(b, b + m) - b;
	for (int i = 0; i <= n + 1; i++) {
		if (a[i] != -1) {
			int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
			if (pos == dp.size()) dp.push_back(a[i]);
			else dp[pos] = a[i];
			len[i] = pos + 1;
		} else {
			int pos = dp.size();
			for (int j = m - 1; j >= 0; j--) {
				while (pos && dp[pos - 1] >= b[j]) pos--;
				if (pos == dp.size()) dp.push_back(b[j]);
				else dp[pos] = b[j];
			}
		}
	}
	int cur = n + 1;
	while (cur != 0) {
		int cnt = 0;
		for (int j = cur - 1; j >= 0; j--) {
			if (a[j] == -1) {cnt++; continue;}
			if (a[j] >= a[cur]) continue;
			if (len[j] + min(cnt, GetNum(a[j] + 1, a[cur] - 1)) + 1 == len[cur]) {
				int pos = lower_bound(b, b + m, a[j] + 1) - b;
				for (int k = j; k <= cur; k++) {
					if (a[k] == -1 && pos < m && b[pos] < a[cur]) {
						a[k] = b[pos], S.erase(S.find(b[pos])), pos++;
					}
				}
				cur = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) a[i] = *S.begin(), S.erase(S.begin());
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
	return 0;
}