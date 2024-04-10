#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int dp[maxn][maxn][maxn], c[maxn][maxn], n, k;
char s[maxn], ceva[maxn];
int main() {
	scanf("%s%d\n", s + 1, &k);
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		char x[5];
		int cost;
		fgets(x, 4, stdin);
		scanf("%d", &cost);
		fgets(ceva, sizeof(ceva), stdin);
		c[x[0] - 'a'][x[2] - 'a'] = cost;
	}

	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int p = 'a'; p <= 'z'; ++p)
				dp[i][j][p - 'a'] = -0x3f3f3f3f;
	for (int i = 'a'; i <= 'z'; ++i)
		if (i != s[1])
			dp[1][1][i - 'a'] = 0;
		else
			dp[1][0][i - 'a'] = 0;
	
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int p = 'a'; p <= 'z'; ++p)
				if (j - static_cast<int>(p != s[i]) >= 0)
					for (int o = 'a'; o <= 'z'; ++o)
						if (dp[i - 1][j - static_cast<int>(p != s[i])][o - 'a'] != -0x3f3f3f3f)
							dp[i][j][p - 'a'] = max(dp[i][j][p - 'a'], dp[i - 1][j - static_cast<int>(p != s[i])][o - 'a'] + c[o - 'a'][p - 'a']), fprintf(stderr, "%d\n", dp[i][j][p - 'a']);
	
	int rez = -0x3f3f3f3f;
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j < 26; ++j) {
			rez = max(rez, dp[n][i][j]);
			if (dp[n][i][j] == 0)
				fprintf(stderr, "%d %d %d ->\n", n, i, j);
			}
	
	printf("%d", rez);
}