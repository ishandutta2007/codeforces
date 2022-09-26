#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10005
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int dp[N][N],n,m;
char s[N],t[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",t+1);
	m=strlen(t+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		dp[i][0]=min(dp[i][0],dp[i-1][0]+1);
		for(int j=1;j<=m;++j){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			if(s[i]==t[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
		}
		if(s[i]^'.'){
			int pos=i,tot=0;
			while(pos<=n){
				tot+=(s[pos]=='.'?-1:1);
				if(!tot)break;
				++pos;
			}
			if(tot!=0)continue;
			for(int j=0;j<=m;++j){
				dp[pos][j]=min(dp[pos][j],dp[i-1][j]);
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}