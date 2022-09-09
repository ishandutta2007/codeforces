#include<bits/stdc++.h>
#define maxn 120
#define maxm 120
using namespace std;
long long a[maxn], b[maxm], c[maxn][maxm];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i += 1) scanf("%lld", a + i);
	for(int i = 0; i < m; i += 1) scanf("%lld", b + i);
	for(int k = 0; k <= 30; k += 1){
		long long r = 0, x = 0;
		for(int i = 1; i < n; i += 1){
			r ^= a[i] & (1 << k);
			c[i][0] += a[i] & (1 << k);
		}
		for(int i = 1; i < m; i += 1){
			x ^= b[i] & (1 << k);
			c[0][i] += b[i] & (1 << k);
		}
		if(((a[0] & (1 << k)) ^ x) != ((b[0] & (1 << k)) ^ r)){
			printf("NO");
			return 0;
		}
		c[0][0] += ((a[0] & (1 << k)) ^ x);
	}
	printf("YES\n");
	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < m; j += 1){
			printf("%lld ", c[i][j]);
		}
		printf("\n");
	}
}