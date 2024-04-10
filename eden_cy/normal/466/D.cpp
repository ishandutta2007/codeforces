#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 2005

typedef long long ll;
const int Mod=(int)1e9+7;

int val[M];
ll dp[M][M];
int main() {
	int n,h;
	scanf("%d%d",&n,&h);
	FOR(i,1,n) {
		scanf("%d",&val[i]);
		val[i]=h-val[i];
	}
	dp[0][0]=1;
	FOR(i,1,n) {
		dp[i][val[i]]=(dp[i-1][val[i]-1]+dp[i-1][val[i]])%Mod;
		dp[i][val[i]-1]=(dp[i-1][val[i]]*val[i])%Mod;
		if(val[i]>0) dp[i][val[i]-1]=(dp[i][val[i]-1]+dp[i-1][val[i]-1]*val[i])%Mod;
	}
	printf("%lld\n",dp[n][0]);
	return 0;
}