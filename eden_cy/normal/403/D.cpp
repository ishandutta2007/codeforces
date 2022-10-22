#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1055
#define N 55

typedef long long ll;
const int Mod=(int)1e9+7;

ll C[M][M];
ll dp[M][N];
int main() {
	FOR(i,0,1050) {
		C[i][0]=1;
		FOR(j,1,min(50,i)) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	dp[0][0]=1;
	FOR(i,0,1000) {
		DOR(k,50,1) FOR(j,i+1,1000) {
			dp[j][k]=(dp[j][k]+dp[j-i-1][k-1])%Mod;
		}
	}
	int Cas;
	scanf("%d",&Cas);
	FOR(t,1,Cas) {
		int n,K;
		scanf("%d%d",&n,&K);
		if(K>50) {
			puts("0");
			continue;
		}
		ll res=0;
		FOR(i,1,n) {
			res=(res+dp[i][K]*C[n-i+K][K])%Mod;
		}
		FOR(i,1,K) res=(res*i)%Mod;
		printf("%lld\n",res);
	}
	return 0;
}