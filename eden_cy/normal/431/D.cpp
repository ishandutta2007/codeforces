#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 65

typedef long long ll;

ll m;
int k;
ll dp[M][M];
int Num[M];
ll dfs(int pos,int sum,bool limit) {
	if(!pos) return !sum;
	if(!limit && ~dp[pos][sum]) return dp[pos][sum];
	ll tmp=0;
	FOR(i,0,limit?Num[pos]:1) if(sum-i>=0) tmp+=dfs(pos-1,sum-i,limit && (i==Num[pos]));
	if(!limit) dp[pos][sum]=tmp;
	return tmp;
}
ll calc(ll x) {
	for(int i=1;i<64;i++,x>>=1) Num[i]=x&1;
	return dfs(63,k,1);
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%lld%d",&m,&k);
	ll L=1,R=1e18,res;
	while(L<=R) {
		ll mid=L+R>>1;
		if(calc(mid<<1)-calc(mid)>=m) res=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",res);
	return 0;
}