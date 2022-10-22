#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair 
using namespace std;

typedef pair <int, int> pii;

const long long INF = 2000000000000000000ll;

string s;
int len[1010][1010];
vector <pii> all;

bool cmp(pii a, pii b) {
	int tmp = min(len[a.fi][b.fi], min(a.se - a.fi + 1, b.se - b.fi + 1));
	if (b.fi + tmp - 1 == b.se) return 0;
	if (a.fi + tmp - 1 == a.se) return 1;
	return s[a.fi + tmp] < s[b.fi + tmp];
}

long long dp[1010][1010], sum[1010];
int be[1010];
int n, m;

long long check(int mid) {
	for (int i = 0; i < n; i++) {
		be[i] = n + 1;
	}
	for (int i = 0; i <= mid; i++) {
		be[all[i].fi] = min(be[all[i].fi], all[i].se + 1);
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int j = 0; j < m; j++) {
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++) {
			sum[be[i]] += dp[i][j];
			sum[be[i]] = min(sum[be[i]], INF);
		}
		for (int i = 1; i <= n; i++) {
			sum[i] += sum[i - 1];
			sum[i] = min(sum[i], INF);
		}
		for (int i = 0; i <= n; i++) {
			dp[i][j + 1] = sum[i];
		}
	}
	return dp[n][m];
}

int main () {
	long long k; cin >> n >> m >> k;
	cin >> s;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			len[i][j] = s[i] == s[j] ? len[i + 1][j + 1] + 1 : 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			all.push_back(mp(i, j));
		}
	}
	sort(all.begin(), all.end(), cmp), reverse(all.begin(), all.end());
	int l = 0, r = all.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid) < k) l = mid + 1;
		else r = mid;
	}
	for (int i = all[l].fi; i <= all[l].se; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}