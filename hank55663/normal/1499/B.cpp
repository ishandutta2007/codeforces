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
bool solve(){
	char c[105];
	scanf("%s",c);
	int dp[105];
	dp[0]=1;
	dp[1]=1;
	for(int i = 2;c[i]!=0;i++){
		dp[i]=0;
		if(c[i]>=c[i-1])dp[i]|=dp[i-1];
		if(c[i]>=c[i-2])dp[i]|=dp[i-2];
		//ans=dp[i];
		//printf("%d",dp[i]);
	}
	int len=strlen(c)-1;
	if(dp[len]||dp[len-1])printf("YES\n");
	else printf("NO\n");
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}