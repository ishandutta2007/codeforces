#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int a[100010], b[100010];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		static int p[100010];
		for (int i = 1; i <= n; i++) {
			p[a[i]] = b[i];
		}
		static int vis[100010]; for (int i = 1; i <= n; i++) vis[i] = 0;
		static vector <int> sz; sz.clear();
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int cur = i, cnt = 0;
			while (!vis[cur]) cnt++, vis[cur] = 1, cur = p[cur];
			sz.push_back(cnt);
		}
		int l = n / 2, r = l + 1, flag = 1;
		for (auto it : sz) {
			if (it & 1) {
				if (flag) r++;
				else l--;
				flag ^= 1;
			}
		}
		long long ans = 0;
		for (int i = 1; i <= l; i++) {
			ans -= 2 * i;
		}
		for (int i = r; i <= n; i++) {
			ans += 2 * i;
		}
		cout << ans << endl;
	}
	return 0;
}