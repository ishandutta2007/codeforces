#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int son[30010][10], fail[30010], tag[30010], TOT;
int dp[60][30010][2];
string s;
string L, R;
int n, m;
queue <int> q;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int dfs(int now, int cur, int flag, const string &a) {
	if (now == -1) return cur == 0;
	if (~dp[now][cur][flag]) return dp[now][cur][flag];
	int &res = dp[now][cur][flag] = 0;
	int dw = 0, up = flag ? a[now] - '0' : 9;
	for (int i = dw; i <= up; i++) {
		ADD(res, dfs(now - 1, son[cur][i], flag & (i == a[now] - '0'), a));
	}
	return res;
}

int main() {
	cin >> s >> L >> R, n = s.size(), m = L.size();
	reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
	int p = 0; while (L[p] == '0') p++;
	L[p]--; for (int i = 0; i < p; i++) L[i] = '9';
	TOT = 1, memset(son, 0, sizeof(son));
	for (int i = 0; i <= n - m / 2; i++) {
		int now = 1;
		for (int j = i; j < i + m / 2; j++) {
			int &nxt = son[now][s[j] - '0'];
			now = (!nxt ? (nxt = ++TOT) : nxt);
		}
		tag[now] = 1;
	}
	fail[1] = 0, q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < 10; i++) {
			int &v = son[x][i];
			if (v) q.push(v);
			(v ? fail[v] : v) = fail[x] ? son[fail[x]][i] : 1;
		}
	}
	for (int i = 1; i <= TOT; i++) {
		for (int j = 0; j < 10; j++) {
			if (tag[son[i][j]]) son[i][j] = 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = dfs(m - 1, 1, 1, R);
	memset(dp, -1, sizeof(dp));
	SUB(ans, dfs(m - 1, 1, 1, L));
	cout << ans << endl;
	return 0;
}