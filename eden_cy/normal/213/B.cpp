#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 105
#define N 15

typedef long long ll;
const int Mod=(int)1e9+7;

ll C[M<<1][M<<1];
ll dp[N][M];
int Num[N];
int main() {
	FOR(i,0,200) {
		C[i][0]=1;
		FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	int n;
	scanf("%d",&n);
	FOR(i,0,9) scanf("%d",&Num[i]);
	FOR(i,0,9) n-=Num[i];
	if(n<0) {
		puts("0");
		return 0;
	}
	dp[10][n]=1;
	int tot=0;
	DOR(i,9,1) {
		FOR(j,0,n) {
			FOR(k,0,j) {
				int t=k+Num[i];
				dp[i][j-k]=(dp[i][j-k]+dp[i+1][j]*C[tot+n-j+t][t])%Mod;
			}
		}
		tot+=Num[i];
	}
	ll res=0;
	FOR(i,0,n) {
		FOR(j,0,i) {
			if(tot+n-i>0) {
				int t=j+Num[0];
				res=(res+dp[1][i]*C[tot+n-i-1+t][t])%Mod;
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}