#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 5005

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,ll b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll dp[M][M];	
int main() {
	int n,K;
	scanf("%d%d",&n,&K);
	dp[1][1]=n;
	FOR(i,2,K) FOR(j,1,min(n,i)) dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1))%Mod;
	ll res=0;
	FOR(i,1,min(n,K)) res=(res+dp[K][i]*Fast(2,n-i))%Mod;
	printf("%lld\n",res);
	return 0;
}