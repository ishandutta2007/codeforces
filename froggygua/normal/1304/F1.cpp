#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 105
#define M 40020
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
int n,m,d;
ll dp[N][M],pre[M],suf[M],ans,a[N][M],s[N][M];
int main(){
	n=read(),m=read(),d=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i+d-1<=m;i++){
		dp[1][i]=s[1][i+d-1]-s[1][i-1]+s[2][i+d-1]-s[2][i-1];
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;j++)pre[j]=max(pre[j-1],dp[i-1][j]);
		for(int j=m-d+1;j>=1;j--)suf[j]=max(suf[j+1],dp[i-1][j]);
		for(int j=1;j<=m-d+1;++j){
			int tmp=s[i+1][j+d-1]-s[i+1][j-1]+s[i][j+d-1]-s[i][j-1];
			for(int k=max(1,j-d+1);k<=min(j+d-1,m-d+1);++k){
				dp[i][j]=max(dp[i][j],dp[i-1][k]+tmp-(s[i][min(j+d-1,k+d-1)]-s[i][max(j,k)-1]));
			}
			if(j-d>=1)dp[i][j]=max(dp[i][j],pre[j-d]+tmp);
			if(j+d<=m)dp[i][j]=max(dp[i][j],suf[j+d]+tmp);
			//dp[i][j]=max(dp[i][j],max(pre[i-1],suf[j+d])+tmp);
		}
	}
	for(int i=1;i<=m-d+1;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}