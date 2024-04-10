#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int P = 260;

int pw[3] = {1, P, P * P};
char s[100010];
int nxt[100010][26];
char t[3][260];
int len[3];
int dp[260][260][260];
char buf[10];

int getn(int a, int b, int c, int d, int e, int f){
	return pw[a] * b + pw[c] * d + pw[e] * f;
}

char getc(){
	scanf("%s", buf);
	return buf[0];
}

void chmin(int &a, int b){a = a < b ? a : b;}

int main(){
	int n, q; scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 0; i < 26; i++){
		nxt[n + 1][i] = nxt[n][i] = n + 1;
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < 26; j++){
			if (s[i + 1] - 'a' == j) nxt[i][j] = i + 1;
			else nxt[i][j] = nxt[i + 1][j];
		}
	}
	dp[0][0][0] = 0;
	while (q--){
		char op = getc();
		int x; scanf("%d", &x);
		x--;
		if (op == '+'){
			char c = getc();
			t[x][++len[x]] = c;
			if (x == 0){
				for (int i = 0; i <= len[1]; i++){
					for (int j = 0; j <= len[2]; j++){
						dp[len[0]][i][j] = INF;
						if (i) chmin(dp[len[0]][i][j], nxt[dp[len[0]][i - 1][j]][t[1][i] - 'a']);
						if (j) chmin(dp[len[0]][i][j], nxt[dp[len[0]][i][j - 1]][t[2][j] - 'a']);
						chmin(dp[len[0]][i][j], nxt[dp[len[0] - 1][i][j]][c - 'a']);
					}
				}
			}
			if (x == 1){
				for (int i = 0; i <= len[0]; i++){
					for (int j = 0; j <= len[2]; j++){
						dp[i][len[1]][j] = INF;
						if (i) chmin(dp[i][len[1]][j], nxt[dp[i - 1][len[1]][j]][t[0][i] - 'a']);
						if (j) chmin(dp[i][len[1]][j], nxt[dp[i][len[1]][j - 1]][t[2][j] - 'a']);
						chmin(dp[i][len[1]][j], nxt[dp[i][len[1] - 1][j]][c - 'a']);
					}
				}
			}
			if (x == 2){
				for (int i = 0; i <= len[0]; i++){
					for (int j = 0; j <= len[1]; j++){
						dp[i][j][len[2]] = INF;
						if (i) chmin(dp[i][j][len[2]], nxt[dp[i - 1][j][len[2]]][t[0][i] - 'a']);
						if (j) chmin(dp[i][j][len[2]], nxt[dp[i][j - 1][len[2]]][t[1][j] - 'a']);
						chmin(dp[i][j][len[2]], nxt[dp[i][j][len[2] - 1]][c - 'a']);
					}
				}
			}
		} else len[x]--;
		printf(dp[len[0]][len[1]][len[2]] <= n ? "YES\n" : "NO\n");
	}
	return 0;
}