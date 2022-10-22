#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 2605
#define N 105

typedef long long ll;
const int Mod=(int)1e9+7;

char str[M];
ll dp[N][M];
ll dfs(int x,int cnt) {
	if(cnt<0) return 0;
	if(!x) return !cnt;
	if(~dp[x][cnt]) return dp[x][cnt];
	dp[x][cnt]=0;
	FOR(i,0,25) dp[x][cnt]=(dp[x][cnt]+dfs(x-1,cnt-i))%Mod;
	return dp[x][cnt];
}
int main() {
	memset(dp,-1,sizeof(dp));
	int Cas;
	scanf("%d",&Cas);
	FOR(t,1,Cas) {
		scanf("%s",str+1);
		int n=strlen(str+1);
		int tot=0;
		FOR(i,1,n) tot+=str[i]-'a';
		printf("%lld\n",(dfs(n,tot)+Mod-1)%Mod);
//		dp[0][tot]=1;
//		FOR(i,1,n) {
//			FOR(j,0,25) {
//				FOR(k,0,2600) {
//					dp[i][k]=(dp[i][k]+dp[i-1][k+j])%Mod;
//				}
//			}
//		}
//		printf("%lld\n",(dp[n][0]+Mod-1)%Mod);
	}
	return 0;
}