#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
#define N 1010
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
int n,m,dp[12][N][N],ans,s[N][N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			dp[1][i][j]=1;
		}
		for(int j=1;j<=n;++j){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+dp[1][i][j];
		}
	}
	for(int i=2;i<=m;++i){
		for(int x=1;x<=n;++x){
			for(int y=x;y<=n;++y){
				dp[i][x][y]=((long long)s[y][y]-s[y][x-1]-s[x-1][y]+s[x-1][x-1]+mod)%mod;
			}
		}
		for(int x=1;x<=n;++x){
			for(int y=1;y<=n;++y){
				s[x][y]=((long long)dp[i][x][y]+s[x-1][y]+s[x][y-1]-s[x-1][y-1]+mod)%mod;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			ans=(ans+dp[m][i][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}