#include <bits/stdc++.h>

const int mod = 998244353;
using ll = long long;
const int maxn = 2e5 + 222;
int f[maxn][2][2][2][2][2],n,p[maxn],ans,sum;
char s[maxn];

int dec(int x) { return x >= mod ? x - mod : x; }

int main() {
	scanf("%s",s + 1);
	n = std::strlen(s + 1);
	for (int i = 1; i <= n; ++ i) {
		p[i] = s[i] - '0';
		ans = ((ll) ans * 2 + p[i]) % mod;
	}
	ans = (ans + 1) % mod;
	ans = (ll) ans * (ans - 1) % mod * (ans - 2) % mod;
	ans = (ans + mod) % mod;
	f[1][1][1][1][0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int a = 0; a <= 1; ++ a)
		for (int b = 0; b <= 1; ++ b)
		for (int c = 0; c <= 1; ++ c)
		for (int p1 = 0; p1 <= 1; ++ p1)
		for (int p2 = 0; p2 <= 1; ++ p2)
		for (int ai = 0; ai <= 1 - ( a&(p[i]==0) ); ++ ai)
		for (int bi = 0; bi <= 1 - ( b&(p[i]==0) ); ++ bi)
		for (int ci = 0; ci <= 1 - ( c&(p[i]==0) ); ++ ci) {
			int na = a & (ai == p[i]);
			int nb = b & (bi == p[i]);
			int nc = c & (ci == p[i]);
			int x = ai ^ bi;
			int y = bi ^ ci;
			if (x & y) continue;
			int &t = f[i+1][na][nb][nc][p1|x][p2|y];
			t = dec(t + f[i][a][b][c][p1][p2]);
		}
	} 
	for (int a = 0; a <= 1; ++ a)
	for (int b = 0; b <= 1; ++ b)
	for (int c = 0; c <= 1; ++ c) 
		sum = (sum + f[n+1][a][b][c][1][1]) % mod;
	//printf("%d\n",sum);
	sum = (ll) sum * 3 % mod;
	ans = (ans - sum + mod) % mod;
	printf("%d",ans);
	return 0;
}