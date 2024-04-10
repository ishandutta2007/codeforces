#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 5005
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,m,dp[N][N],ans;
char s[N],t[N];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i]==t[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}