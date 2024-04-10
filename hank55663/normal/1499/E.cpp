#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
const int mod=998244353;
int dp[1005][1005][2];
bool solve(){
	char c[1005],c2[1005];
	int last[1005],last2[1005];
	scanf("%s %s",c+1,c2+1);
	for(int i=1;c[i]!=0;i++){
		last[i]=1;
		for(int j = i;j>1;j--){
			if(c[j]!=c[j-1])last[i]++;
			else break;
		}
	}
	for(int i = 1;c2[i]!=0;i++){
		last2[i]=1;
		for(int j = i;j>1;j--){
			if(c2[j]!=c2[j-1])last2[i]++;
			else break;
		}
	}
	LL ans=0;
	for(int i = 1;c[i]!=0;i++){
		for(int j = 1;c2[j]!=0;j++){
			//if(i!=1){
			if(c[i-1]!=c[i])dp[i][j][0]+=dp[i-1][j][0];
			if(c[i]!=c2[j])dp[i][j][0]+=dp[i-1][j][1];
			if(c2[j-1]!=c2[j])dp[i][j][1]+=dp[i][j-1][1];
			if(c2[j]!=c[i])dp[i][j][1]+=dp[i][j-1][0];
			if(c[i]!=c2[j]){
				dp[i][j][0]+=last2[j];
				dp[i][j][1]+=last[i];
			}
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
			ans+=dp[i][j][0]+dp[i][j][1];
			ans%=mod;
			//printf("%d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
				//}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t=1;//000000;
	//scanf("%d",&t);
	while(t--)solve();
}