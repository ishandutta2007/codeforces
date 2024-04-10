#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const string CHK = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

typedef unsigned long long ull;

char t[100010];
string s;
char buf[1000010];
int sum[26][100010];
long long pw[1000010];
int fail[1000010];

void get_fail(int m) {
	int j = -1;
	fail[0] = -1;
	for (int i = 1; i <= m; i++) {
		while (j >= 0 && buf[j] != buf[i - 1]) j = fail[j];
		fail[i] = ++j;
		if (i != m && buf[i] == buf[fail[i]] && fail[fail[i]] != -1) fail[i] = fail[fail[i]];
	}
}

int get_match(int m, const string &s) {
	int ans = 0;
	for (int i = 0, k = 0; i < s.size(); i++) {
		while (k >= 0 && (k > m || buf[k] != s[i])) k = fail[k];
		if (++k >= m) ans++;
	}
	return ans;
}

int main () {
	pw[0] = 1;
	for (int i = 1; i <= 1000005; i++) {
		pw[i] = pw[i - 1] * 2 % mod;
	}
	int n, q; scanf("%d%d", &n, &q);
	scanf("%s%s", buf, t + 1);
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = (t[j] - 'a' == i);
			if (j) sum[i][j] = (sum[i][j - 1] * 2ll + sum[i][j]) % mod;
		}
	}
	s = buf;
	while (q--) {
		int k; scanf("%d%s", &k, buf);
		int len = strlen(buf);
		get_fail(len);
		string cur = s; int cnt = 0;
		while (cnt < k && cur.size() < len) cur = cur + t[cnt + 1] + cur, cnt++;
		if (cur.size() < len) {
			printf("0\n");
			continue;
		}
		long long ans = get_match(len, cur) * pw[k - cnt] % mod;
		string pre, suc;
		for (int i = 0; i < len - 1; i++) {
			suc.push_back(cur[i]);
		}
		for (int i = cur.size() - len + 1; i < cur.size(); i++) {
			pre.push_back(cur[i]);
		}
		string P = pre + '{' + suc;
		for (int i = 0; i < 26; i++) {
			long long mul = (sum[i][k] - sum[i][cnt] * pw[k - cnt] % mod + mod) % mod;
			if (!mul) continue;
			P[len - 1] = char('a' + i);
			int tmp = get_match(len, P);
			ans = (ans + tmp * mul) % mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}