#include<bits/stdc++.h>
using namespace std;
#define N 123
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
int n,a[N];
ll w[N],dp[N][N][N];
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			w[i]=max(w[i],w[i-j]+a[j]);		
		}
	}
	for(int len=1;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			for(int p=0;p<=n;++p){
				for(int k=l;k<r;++k){
					if(s[k]==s[r]){
						dp[l][r][p]=max(dp[l][r][p],dp[l][k][p+1]+dp[k+1][r-1][0]);
					}
				}	
			}
			for(int p=0;p<=n;++p){
				dp[l][r][p]=max(dp[l][r][p],dp[l][r-1][0]+w[p+1]);	
			}
		}
	}
	printf("%lld\n",dp[1][n][0]);
	return 0;
}