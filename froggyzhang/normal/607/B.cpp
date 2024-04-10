#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 505
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,dp[N][N],a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		dp[i][i]=1;
		dp[i-1][i]=(a[i]!=a[i-1])+1;
	}
	for(int len=3;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			dp[l][r]=n;
			if(a[l]==a[r])dp[l][r]=dp[l+1][r-1];	
			for(int k=l;k<r;++k){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}