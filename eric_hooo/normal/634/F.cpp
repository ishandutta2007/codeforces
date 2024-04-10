#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int m, t, k;
vector <int> poi[3010];
int pre[3010], suc[3010];
int sum;
int L[12], R[12], tl, tr;
int alive[3010];
int Y[3010];
vector <pii> all;

void Erase(int id) {
	if (pre[id] != -1) suc[pre[id]] = suc[id];
	if (suc[id] != -1) pre[suc[id]] = pre[id];
	tl = tr = 0;
	int x = Y[id];
	int it = suc[id];
	int cur = it;
	while (tr < k && cur != t + 1) R[tr++] = Y[cur], cur = suc[cur];
	cur = it;
	while (tl < k && pre[cur] != 0) cur = pre[cur], L[tl++] = Y[cur];
	for (int i = 0; i < tl; i++) {
		if (k - 2 - i < 0) break;
		if (k - 2 - i < tr) sum += (L[i] - (i + 1 == tl ? 0 : L[i + 1])) * (m + 1 - R[k - 2 - i]);
		if (k - 3 - i < (int)tr) sum -= (L[i] - (i + 1 == tl ? 0 : L[i + 1])) * (m + 1 - (k - 2 - i ? R[k - 3 - i] : x));
	}
	if (k == 1) sum -= (x - (tl ? L[0] : 0)) * (m + 1 - x);
	else if (k - 2 < tr) sum -= (x - (tl ? L[0] : 0)) * (m + 1 - R[k - 2]);
	if (tr && k - 1 < tr) {
		sum += (x - (tl ? L[0] : 0)) * (m + 1 - R[k - 1]);
	}
}

int main() {
	int n;
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for (int i = 1; i <= t; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Y[i] = y;
		poi[x].push_back(i), all.push_back(mp(y, i));
	}
	sort(all.begin(), all.end());
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		memset(alive, 0, sizeof(alive)), memset(pre, -1, sizeof(pre)), memset(suc, 0, sizeof(suc));
		for (int j = i; j <= n; j++) {
			for (auto it : poi[j]) {
				alive[it] = 1;
			}
		}
		int lst = 0;
		for (auto it : all) {
			if (!alive[it.se]) continue;
			if (lst != -1) pre[it.se] = lst, suc[lst] = it.se;
			lst = it.se;
		}
		suc[lst] = t + 1, pre[t + 1] = lst;
		int L = suc[0], R = suc[0];
		for (int i = 1; i < k; i++) {
			if (R == t + 1) break;
			R = suc[R];
		}
		while (R != t + 1) sum += (Y[L] - Y[pre[L]]) * (m + 1 - Y[R]), L = suc[L], R = suc[R];
		for (int j = n; j >= i; j--) {
			ans += sum;
			for (auto it : poi[j]) {
				Erase(it);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}