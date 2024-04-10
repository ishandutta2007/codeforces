#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020
const int mod=998244353;
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
int n,m,dp[N][N],a[N],s[N],ans,p[N][N],q[N][N];
int main(){
	n=read(),m=read()-1;
	dp[0][0]=p[0][0]=q[0][0]=1;
	for(int i=1;i<=n;i++){
		p[0][i]=p[0][i-1];
		q[i][0]=q[i-1][0];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i][j]+p[i-j][min(i-j,j)])%mod;
			dp[i][j]=(dp[i][j]+q[i-1][j])%mod;
			dp[i][j]=(dp[i][j]-q[i-j][j]+mod)%mod;
		}
		for(int j=1;j<=n;j++){
			p[i][j]=(p[i][j-1]+dp[i][j])%mod;
		}
		for(int j=0;j<=n;j++){
			q[i][j]=(q[i-1][j]+dp[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=(dp[n][i]<<1)%mod;
		s[i]=(s[i-1]+dp[n][i])%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+1LL*a[i]*s[min(n,m/i)])%mod;
	}
	cout<<ans<<endl;
	return 0;
}