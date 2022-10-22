#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

typedef unsigned long long ull;

int dp[500010];
ull lst[510][7813];

void SET(int x, int y) {
	lst[x][y >> 6] |= 1ull << (y & 63);
}

int GET(int x, int y) {
	return lst[x][y >> 6] >> (y & 63) & 1;
}

void calc(vector <int> &a, vector <int> &b) {
	int sum = 0;
	dp[0] = 1;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
		for (int j = 0; j <= (sum >> 6); j++) {
			lst[i][j] = 0;
		}
		for (int j = sum; j >= 0; j--) {
			if (j >= a[i] && dp[j - a[i]]) dp[j] = 1, SET(i, j);
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (i * 2 != sum) dp[i] = 0;
	}
	if (sum & 1) return ;
	if (!dp[sum / 2]) return ;
	dp[sum / 2] = 0;
	int x = (int)a.size() - 1, y = sum / 2;
	while (x != -1) {
		int val = GET(x, y);
		y -= val * a[x];
		if (val) b.push_back(a[x]), a.erase(a.begin() + x);
		x--; 
	}
	return ;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d", &n);
		vector <int> a1, a2, b1, b2;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			a1.push_back(x);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			b1.push_back(x);
		}
		if (n != m) {
			printf("No\n");
			continue;
		}
		calc(a1, a2), calc(b1, b2);
		if (!a2.size() || !b2.size()) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		if (a1.size() == b1.size()) {
			sort(a1.rbegin(), a1.rend()), sort(b1.begin(), b1.end());
			int x = 0, y = 0;
			for (int i = 0; i < a1.size(); i++) {
				x += a1[i];
				printf("%d %d\n", x, y);
				y += b1[i];
				printf("%d %d\n", x, y);
			}
			sort(a2.rbegin(), a2.rend()), sort(b2.begin(), b2.end());
			for (int i = 0; i < a2.size(); i++) {
				x -= a2[i];
				printf("%d %d\n", x, y);
				y -= b2[i];
				printf("%d %d\n", x, y);
			}
			continue;
		}
		vector <pii> ans;
		int flag = 0;
		if (a1.size() > b1.size()) flag = 1, swap(a1, b1), swap(a2, b2);
		int x = 0, y = 0;
		sort(a1.rbegin(), a1.rend()), sort(b1.rbegin(), b1.rend());
		for (int i = 0; i < a1.size(); i++) {
			x += a1[i];
			ans.push_back(mp(x, y));
			y += b1.back(), b1.pop_back();
			ans.push_back(mp(x, y));
		}
		sort(a2.rbegin(), a2.rend()), sort(b1.rbegin(), b1.rend());
		for (int i = 0; i < b1.size(); i++) {
			x -= a2.back(), a2.pop_back();
			ans.push_back(mp(x, y));
			y += b1[i];
			ans.push_back(mp(x, y));
		}
		sort(a2.rbegin(), a2.rend()), sort(b2.begin(), b2.end());
		for (int i = 0; i < a2.size(); i++) {
			x -= a2[i];
			ans.push_back(mp(x, y));
			y -= b2[i];
			ans.push_back(mp(x, y));
		}
		if (flag) {
			for (int i = 0; i < ans.size(); i++) {
				swap(ans[i].fi, ans[i].se);
			}
			reverse(ans.begin(), ans.end());
		}
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d\n", ans[i].fi, ans[i].se);
		}
	}
	return 0;
}