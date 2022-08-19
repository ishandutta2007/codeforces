#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, m, p[maxn][2];
int f[maxn], h[maxn], s[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	vector<pi> r;
	for (int i = 1; i <= m; i++)
		cin >> f[i] >> h[i], r.pb(mp(f[i], h[i]));
	sort(r.begin(), r.end());
	for (int i = 1; i <= m; i++)
		f[i] = r[i - 1].fi, h[i] = r[i - 1].se;
	for (int i = 1; i <= m; ) {
		int j = i;
		while (f[j] == f[i]) j++;
		vi cur;
		for (int u = 1; u <= n; u++)
			if (s[u] == f[i]) cur.pb(u);
		for (int s = i; s < j; s++)
			if (h[s] > cur.size()) p[s][0] = n + 1, p[s][1] = 0;
			else p[s][0] = cur[h[s] - 1], p[s][1] = cur[cur.size() - h[s]];
		i = j;
	}
//	for (int i = 1; i <= m; i++)
//		cout << p[i][0] << ' ' << p[i][1] << endl;
	int mm = 0, rr = 0;
	for (int i = 0; i <= n; i++) {
		int mx = 0;
		ll ans = 1;
		int fl = 0;
		for (int j = 1; j <= m; ) {
			int k = j;
			while (f[k] == f[j]) k++;
			int cnt[4] = {0, 0, 0, 0};
			int cf = 0; 
			for (int u = j; u < k; u++) {
				int st = 0;
				if (p[u][0] <= i) st ^= 1;
				if (p[u][1] > i) st ^= 2;
				if (p[u][0] == i) {
					cf = 1;
					continue;
				}
				cnt[st]++;
			} 
			if (cf) {
				fl = 1;
				mx++;
				if (cnt[2] || cnt[3]) mx++, ans = ans * (cnt[2] + cnt[3]) % mod;
			}
			else {
				ll tm = (cnt[1] + cnt[3]) * (cnt[2] + cnt[3]) - cnt[3];
				if (tm > 0) mx += 2, ans = ans * tm % mod;
				else {
					int s = cnt[1] + cnt[2] + cnt[3] * 2;
					if (s)
						mx++, ans = ans * s % mod;
				} 
			}
			j = k;
		}
	//	cout << i << ' ' << mx << ' ' << ans << ' ' << fl << endl;
		if (!fl && i != 0) continue;
		if (mx < mm) continue;
		else if (mx > mm) mm = mx, rr = ans;
		else rr = (rr + ans) % mod;
	}
	cout << mm << ' ' << rr << endl;
	return 0;
}