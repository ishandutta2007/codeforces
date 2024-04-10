#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmax(T &x, T y) {return x < y ? x = y, 1 : 0;}

int n, q;
int a[20010];
vector <int> qry[20010];
int f[20010][15][31];
deque <int> st;
int ans[20010];
int L[20010], R[20010], K[20010];
int bel[20010];

int main() {
	scanf("%d%d", &n, &q);
	; for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &L[i], &R[i], &K[i]);
		if (L[i] != R[i]) qry[L[i]].push_back(i);
	}
	; for (int j = 0; j < 15; j++) for (int k = 0; k <= 30; k++) f[n + 1][j][k] = n + 1;
	st.push_back(n + 1), bel[n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		// cerr << " i:" << i << endl;
		while (st.size() > 1 && st[0] + a[st[0]] <= i + a[i]) st.pop_front();
		; for (int j = i; j < st[0]; j++) bel[j] = i;
		st.push_front(i);
		for (int k = 0; k <= 30; k++) {
			f[i][0][k] = min(i + a[i] + k, n + 1);
			// for (int t = 0; t <= k && i + t <= n; t++) {
			// 	chmax(f[i][0][k], min(n + 1, i + t + a[i + t] + k - t));
			// }
		}
		for (int j = 1; j < 15; j++) for (int k = 0; k <= 30; k++) {
			for (int t = 0; t <= k; t++) {
				chmax(f[i][j][k], f[bel[f[i][j - 1][t]]][j - 1][k - t]);
			}
		}
		// cerr << "   f:" << f[i][0][0] << endl;
		for (auto id : qry[i]) {
			int &ans = :: ans[id] = 0;
			static int tmp[31];
			; for (int k = 0; k <= 30; k++) tmp[k] = i;
			for (int j = 14; j >= 0; j--) {
				static int ttt[31]; memset(ttt, 0, sizeof(ttt));
				for (int k = 0; k <= 30; k++) {
					for (int t = 0; t <= k; t++) {
						chmax(ttt[k], f[bel[tmp[t]]][j][k - t]);
					}
				}
				if (ttt[K[id]] < R[id]) {
					memcpy(tmp, ttt, sizeof(ttt));
					ans |= 1 << j;
				}
			}
			ans++;
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}