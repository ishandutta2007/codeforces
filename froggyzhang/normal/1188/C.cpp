#include<bits/stdc++.h>
using namespace std;
#define N 1010
const int mod=998244353;
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
int n,m,a[N],ans;
int Solve(int x){
	static int dp[N][N],pre[N];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<=m;++i)pre[i]=0;
	dp[0][0]=1;
	for(int i=1,z=0;i<=n;++i){
		while(a[i]-a[z]>=x){
			for(int j=0;j<=m;++j){
				pre[j]=(pre[j]+dp[z][j])%mod;
			}
			++z;
		}
		for(int j=1;j<=m;++j){
			dp[i][j]=pre[j-1];
		}
	}
	int tot=0;
	for(int i=0;i<=n;++i)tot=(tot+dp[i][m])%mod;
	return tot;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	a[0]=-1e9;
	for(int i=1;i<=a[n]/(m-1);++i){
		ans=(ans+Solve(i))%mod;	
	}
	printf("%d\n",ans);
	return 0;
}