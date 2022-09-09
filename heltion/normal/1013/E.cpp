#include<bits/stdc++.h>
#define maxn 6000
#define maxk 3000
using namespace std;
typedef long long LL;
const LL INF = 10000000000;
LL a[maxn], F[maxn][maxk][2];
int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("0");
		return 0;
	} 
	for(int i = 1; i <= n; i += 1) scanf("%lld", a + i);
	for(int j = 1; j <= (n + 1) / 2; j += 1) F[0][j][0] = F[0][j][1] = INF;
	for(int i = 0; i <= n; i += 1) F[i][0][1] = INF;
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= (n + 1) / 2; j += 1){
			F[i][j][0] = min(F[i - 1][j][0], F[i - 1][j][1]);
			LL fir = 0, sec = 0;
			if(i != n) fir = sec = max(a[i + 1] - a[i] + 1, 0LL);
			if(i >= 2){
				fir += F[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0LL);
				sec += F[i - 2][j - 1][1] + max(min(a[i - 2] - 1, a[i - 1]) - a[i] + 1, 0LL);
				F[i][j][1] = min(fir, sec);
			}
			else F[i][j][1] = j == 1 ? max(a[i + 1] - a[i] + 1, 0LL) : INF;
			if(i == n) printf("%lld ", min(F[i][j][0], F[i][j][1]));
			//printf("F[%d][%d][%d] = %lld, F[%d][%d][%d] = %lld\n", i, j, 0, F[i][j][0], i, j, 1, F[i][j][1]);
		}
	}
	
}