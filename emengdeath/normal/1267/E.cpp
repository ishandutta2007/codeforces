#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R + 1) >> 1)
using namespace std;
const int MAXN = 150;
const int mod = 998244353;
typedef long long LL;
typedef pair<int, int> PII;
int n, m, T, h[MAXN], a[MAXN][MAXN];
bool cmp(const int &o, const int &p) {
	return a[o][T] - a[o][n - 1] > a[p][T] - a[p][n - 1];
}
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	vector<int> tmp;
	for (int i = 0; i < m; ++i) h[i] = i, tmp.push_back(i);
	for (T = 0; T + 1 < n; ++T) {
		sort(h, h + m, cmp);
		int now = 0;
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			if (now + a[h[i]][T] - a[h[i]][n - 1] >= 0) {
				now += a[h[i]][T] - a[h[i]][n - 1];
				cnt++;
			}
		}
		if (cnt > ans) {
			ans = cnt;
			tmp.clear();
			for (int i = cnt; i < m; ++i) tmp.push_back(h[i]);
		}
	}
	cout << m - ans << endl;
	for (auto &i : tmp) {
		cout << i + 1 << " ";
	}
	return 0;
}