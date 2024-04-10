#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("-1"); exit(0);}

#define maxn 20

LL F[maxn][maxn][2];
int s[maxn];

LL solve(LL n){
	int m = 0;
	for (; n; n /= 10) s[m += 1] = n % 10;
	reverse(s + 1, s + m + 1);
	for(int i = 0; i < maxn; i += 1)
		for(int j = 0; j < maxn; j += 1)
			for(int k = 0; k < 2; k += 1) F[i][j][k] = 0;
	F[0][0][0] = 1;
	for (int i = 0; i < m; i += 1)
		for (int j = 0; j < 4; j += 1)
			for (int k = 0; k < 2; k += 1)
				if (F[i][j][k])
					for (int tmp = k ? 9 : s[i + 1]; tmp >= 0; tmp--){
						int nj = j + (tmp > 0);
						if (nj <= 3) F[i + 1][nj][k || (tmp < s[i + 1])] += F[i][j][k];
					}
	LL res = 0;
	for (int j = 0;j <= 3;j += 1)
		res += F[m][j][0] + F[m][j][1];
	return res;
}
int main(){
	int T = read();
	while (T --){
		LL L = read(), R = read();
		printf("%lld\n", solve(R) - solve(L - 1));
	}
}