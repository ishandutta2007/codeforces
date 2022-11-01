#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 200005;
int T, pmx[MAXN], pmn[MAXN], smx[MAXN], smn[MAXN], sum[MAXN], n, m;
char s[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d%d", &n, &m);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1];
			if (s[i] == '+') ++sum[i];
			else --sum[i];
			pmx[i] = max(pmx[i - 1], sum[i]);
			pmn[i] = min(pmn[i - 1], sum[i]);
		}
		smx[n + 1] = -1e9, smn[n + 1] = 1e9;
		for (int i = n; i > 0; i--) {
			smx[i] = max(smx[i + 1], sum[i]);
			smn[i] = min(smn[i + 1], sum[i]);
		}
		for (int i = 1; i <= m; i++) {
			int l, r; scanf("%d%d", &l, &r);
			int d = sum[r] - sum[l - 1];
			int mx = max(pmx[l - 1], -d + smx[r + 1]);
			int mn = min(pmn[l - 1], -d + smn[r + 1]);
			printf("%d\n", mx - mn + 1);
		}
	}
	return 0;
}