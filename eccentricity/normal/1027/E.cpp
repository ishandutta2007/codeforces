#include<bits/stdc++.h>
#define maxn 1000 
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL F[maxn][maxn];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i += 1) F[0][i] = 1;
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= n; j += 1){
			for(int k = 1; k <= min(i, j); k += 1){
				F[i][j] = (F[i][j] + F[i - k][j]) % MOD;
			}
			//printf("F[%d][%d] = %lld\n", i, j, F[i][j]);
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1){
			if(i * j < k){
				//printf("%d %d\n", i, j);
				ans = (ans + (F[n][i] - F[n][i - 1] + MOD) % MOD * ((F[n][j] - F[n][j - 1] + MOD) % MOD) * 2 % MOD) % MOD;
			}
		}
	printf("%lld", ans);
}