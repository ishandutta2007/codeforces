#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
const int B=251*501;
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
int n,mod,dp[2][N*N],ans,A[N];
int main(){
	n=read(),mod=read();
	A[0]=1;
	for(int i=1;i<=n;++i){
		A[i]=1LL*A[i-1]*(n-i+1)%mod;
	}
	dp[0][B]=1;
	#define update(x,y) x=(x+y)%mod
	for(int i=1;i<n;++i){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		int C=(i+1)*(i+1)/2;
		for(int j=B-C;j<=B+C;++j){
			int w=dp[(i-1)&1][j];
			if(w){
				update(dp[i&1][j+i+1],w);
				update(dp[i&1][j-i+1],w);
				update(dp[i&1][j+1],1LL*(mod-2)*w);
			}
		}
		int zyk=2;
		while(zyk--){
			for(int j=B+C;j>=B-C;--j){
				update(dp[i&1][j],dp[i&1][j+1]);
			}
			for(int j=B-C;j<=B+C;++j)dp[i&1][j]=dp[i&1][j+1];
		}
		static int suf[N*N];
		for(int j=C;j>=0;--j){
			suf[j]=(suf[j+1]+dp[i&1][B+j])%mod;
		}
		for(int a=0;a<=i;++a){
			for(int b=a+1;b<=i;++b){
				update(ans,1LL*A[n-i-1]*suf[b-a+1]);		
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}