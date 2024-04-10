#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 105
#define N 18

typedef long long ll;

ll dp[1<<N][M];
int Num[N],cnt[N];
int main(){
	ll n;int m;
	scanf("%lld%d",&n,&m);
	int top=0;
	for(;n;n/=10) Num[top++]=n%10;
	
	FOR(i,0,top-1) if(Num[i]) dp[1<<i][Num[i]%m]=1;
	
	FOR(i,0,(1<<top)-1) 
		FOR(k,0,m-1) if(dp[i][k])
			FOR(j,0,top-1) if(!(i&(1<<j)))
				dp[i|(1<<j)][(k*10+Num[j])%m]+=dp[i][k];
				
	ll res=dp[(1<<top)-1][0];
	FOR(i,0,top-1) res/=++cnt[Num[i]];
	printf("%lld\n",res);
	return 0;
}