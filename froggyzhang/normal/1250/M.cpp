#include<bits/stdc++.h>
using namespace std;
#define N 12
typedef long long ll;
typedef unsigned long long ull;
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
const int n=10;
int a[N][N];
double dp[N][N];
int main(){
	dp[1][1]=0;
	for(int i=2;i<=6;++i){
		dp[1][i]=1;
		for(int j=1;j<i;++j){
			dp[1][i]+=1.0/6*dp[1][j];	
		}
		dp[1][i]*=6.0/(i-1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		if(i&1){
			for(int j=1;j<=n;++j){
				if(i==1&&j<=6)continue;
				for(int k=1;k<=6;++k){
					int x=(j<=k?i-1:i);
					int y=(j<=k?1-j+k:j-k);
					dp[i][j]+=1.0/6*min(dp[x][y],dp[x-a[x][y]][y]);	
				}
				dp[i][j]+=1.0;
			}
		}
		else{
			for(int j=n;j>=1;--j){
				for(int k=1;k<=6;++k){
					int x=(j+k<=n?i:i-1);
					int y=(j+k<=n?j+k:2*n-k-j+1);
					dp[i][j]+=1.0/6*min(dp[x][y],dp[x-a[x][y]][y]);
				}
				dp[i][j]+=1.0;
			}	
		}
	}
	printf("%.10lf\n",dp[n][1]);
	return 0;
}