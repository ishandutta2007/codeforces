#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 88
const int inf=0x3f3f3f3f;
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
int n,k,a[N][N],dp[N][12],col[N],ans;
int main(){
	srand(time(0));
	n=read(),k=read();
	ans=inf;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for(int T=1;T<=200000000/(n*n*k);++T){
		for(int i=1;i<=n;++i){
			col[i]=(rand()&1);
		}
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		for(int p=1;p<=k;++p){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(col[i]==col[j])continue;
					dp[i][p]=min(dp[i][p],dp[j][p-1]+a[j][i]);
				}
			}
		}
		ans=min(ans,dp[1][k]);
	}
	printf("%d\n",ans);
	return 0;
}