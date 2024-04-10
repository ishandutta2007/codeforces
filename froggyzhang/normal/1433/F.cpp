#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 72
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
int n,m,k,a[N][N];
int mx[N][N];
void Solve1(int x){
	static int dp[N][N][N];
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=m;++i){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		for(int j=1;j<=min(m>>1,i);++j){
			for(int p=0;p<k;++p){
				dp[i][j][(p+a[x][i])%k]=max(dp[i][j][(p+a[x][i])%k],dp[i-1][j-1][p]+a[x][i]);
			}
		}
	}
	for(int j=1;j<=m>>1;++j){
		for(int p=0;p<k;++p){
			mx[x][p]=max(mx[x][p],dp[m][j][p]);
		}
	}
}
int Solve2(){
	static int dp[N][N];
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		for(int j=0;j<k;++j){
			for(int p=0;p<k;++p){
				dp[i][(p+j)%k]=max(dp[i][(p+j)%k],dp[i-1][p]+mx[i][j]);
			}
		}
	}
	return dp[n][0];
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	memset(mx,~0x3f,sizeof(mx));
	for(int i=1;i<=n;++i){
		Solve1(i);
	}
	printf("%d\n",Solve2());
	return 0;
}