#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 82
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,a[N],len,dp[N][N<<1][N*N>>1];
int main(){
	n=read();
	len=1;
	for(int i=1;i<=n;++i){
		int x=read();
		if(x)++len;
		else ++a[len];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][n][0]=0;
	for(int i=0;i<len;++i){
		for(int j=0;j<=n<<1;++j){
			for(int k=0;k<=n*(n-1)/2;++k){
				if(dp[i][j][k]==inf)continue;
				for(int p=0;p<=n-len+1;++p){
					int t=j+a[i+1]-p;
					if(t>=0&&t<=n<<1){
						int gu=k+(t<n?n-t:t-n);
						dp[i+1][t][gu]=min(dp[i+1][t][gu],dp[i][j][k]+p*(p-1)/2);
					}
				}
			}
		}
	}
	for(int i=0,now=inf;i<=n*(n-1)/2;++i){
		now=min(now,dp[len][n][i]);
		printf("%d ",(n-len)*(n-len+1)/2-now);
	}
	return 0;
}