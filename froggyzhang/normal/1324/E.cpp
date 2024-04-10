#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020
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
int n,h,l,r,dp[N][N],a[N],ans;
int main(){
	n=read(),h=read(),l=read(),r=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<h;j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][(j-a[i]+h)%h],dp[i-1][(j-a[i]+1+h)%h])+(j>=l&&j<=r));
		}
	}
	for(int i=0;i<h;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}