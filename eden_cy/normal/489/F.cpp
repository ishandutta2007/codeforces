#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 505

typedef long long ll;

int n,m,Mod;
char pic[M][M];
ll dp[M][M];
ll dfs(int pos,int cnt1) {
	if(!pos) return 1;
	if(~dp[pos][cnt1]) return dp[pos][cnt1];
	int cnt2=(pos*2-cnt1)/2;
	dp[pos][cnt1]=0;
	if(cnt1>1) dp[pos][cnt1]=(dp[pos][cnt1]+cnt1*(cnt1-1)/2*dfs(pos-1,cnt1-2))%Mod;
	if(cnt2>1) dp[pos][cnt1]=(dp[pos][cnt1]+cnt2*(cnt2-1)/2*dfs(pos-1,cnt1+2))%Mod;
	if(cnt1 && cnt2) dp[pos][cnt1]=(dp[pos][cnt1]+cnt1*cnt2*dfs(pos-1,cnt1))%Mod;
	return dp[pos][cnt1];
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&m,&Mod);
	FOR(i,1,m) scanf("%s",pic[i]+1);
	int cnt1=0;
	FOR(i,1,n) {
		int cnt=0;
		FOR(j,1,m) if(pic[j][i]=='1') cnt++;
		if(cnt==1) cnt1++;
	}
	printf("%lld\n",dfs(n-m,cnt1));
	return 0;
}