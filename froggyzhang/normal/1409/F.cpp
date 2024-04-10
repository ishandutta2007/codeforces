#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int n,m,dp[N][N][N],ans;
char s[N],t[5];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	if(t[1]==t[2]){
		int cnt=0;
		for(int i=1;i<=n;++i)cnt+=(s[i]==t[1]);
		cnt=min(cnt+m,n);
		return !printf("%d\n",cnt*(cnt-1)/2);
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			for(int k=0;k<=m;++k){
				int &now=(dp[i][j][k]=dp[i-1][j][k]);
				if(j&&k-(s[i]!=t[1])>=0)now=max(now,dp[i-1][j-1][k-(s[i]!=t[1])]);
				if(   k-(s[i]!=t[2])>=0)now=max(now,dp[i-1][j][k-(s[i]!=t[2])]+j);
				ans=max(ans,now);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}