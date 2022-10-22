#include <bits/stdc++.h>
using namespace std;

int ID(const char &c) {return c >= 'a' && c <= 'z' ? c - 'a' : c - 'A' + 26;}

char DI(const int &x) {return x < 26 ? 'a' + x : x - 26 + 'A';}

int n;
string s[20];
vector <int> pos[20][52];
int dp[52 << 10], in[52 << 10], lst[52 << 10], alive[52 << 10];
queue <int> q;
vector <int> G[52 << 10];

void Main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < 52; j++) {
			pos[i][j].clear();
		}
		for (int j = 0; j < s[i].size(); j++) {
			pos[i][ID(s[i][j])].push_back(j);
		}
	}
	for (int j = 0; j < (52 << n); j++) {
		G[j].clear(), in[j] = 0;
	}
	for (int j = 0; j < 52; j++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			alive[j << n | mask] = 0;
			for (int i = 0; i < n; i++) {
				if ((mask >> i & 1) >= pos[i][j].size()) goto BAD;
			}
			alive[j << n | mask] = 1;
			for (int nj = 0; nj < 52; nj++) {
				int mmm = 0;
				for (int i = 0; i < n; i++) {
					int np = upper_bound(pos[i][nj].begin(), pos[i][nj].end(), pos[i][j][mask >> i & 1]) - pos[i][nj].begin();
					if (np == pos[i][nj].size()) goto END;
					mmm |= np << i;
				}
				G[j << n | mask].push_back(nj << n | mmm), in[nj << n | mmm]++;
				END:;
			}
			BAD:;
		}
	}
	memset(dp, 0, sizeof(dp)), memset(lst, -1, sizeof(lst));
	for (int j = 0; j < (52 << n); j++) {
		if (!in[j] && alive[j]) q.push(j);
	}
	int ans = 0, cur = -1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		dp[x]++;
		for (auto v : G[x]) {
			if (dp[v] < dp[x]) {
				dp[v] = dp[x], lst[v] = x;
			}
			in[v]--;
			if (!in[v]) q.push(v);
		}
		if (ans < dp[x]) {
			ans = dp[x], cur = x;
		}
	}
	printf("%d\n", ans);
	string str;
	while (cur != -1) {
		str.push_back(DI(cur >> n)), cur = lst[cur];
	}
	reverse(str.begin(), str.end());
	printf("%s\n", str.c_str());
}

int main() {
	int T; cin >> T;
	while (T--) Main();
	return 0;
}