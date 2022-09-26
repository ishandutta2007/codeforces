#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
const ll mod=1e9+7;
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
int n,m;
ll dp[N][2][2];
ll ans=0;
void solve(int n){
	memset(dp,0,sizeof(dp));
	dp[1][0][0]=dp[1][1][1]=1;
	dp[2][0][1]=dp[2][1][0]=dp[2][1][1]=dp[2][0][0]=1;
	for(int i=3;i<=n;i++){
		dp[i][0][1]=dp[i-1][1][1]+dp[i-1][1][0];
		dp[i][1][0]=dp[i-1][0][1]+dp[i-1][0][0];
		dp[i][0][0]=dp[i-1][0][1];
		dp[i][1][1]=dp[i-1][1][0];
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				dp[i][j][k]%=mod;
			}
		}
	}
	ans+=dp[n][0][1]+dp[n][1][0]+dp[n][1][1]+dp[n][0][0];
	ans%=mod;
}
int main(){
	n=read(),m=read();
	solve(n),solve(m);
	cout<<(ans-2+mod)%mod<<endl;
	return 0;
}