#include<bits/stdc++.h>
using namespace std;
#define N 3003
typedef long long ll;
const int mod=998244353;
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
int n,C,a[N],ans[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
namespace Sol_1{
	int dp[2][N][1<<12];
	void Solve(){
		for(int i=1;i<=n;++i)--a[i];
		dp[0][0][0]=1;
		int all=(1<<C)-1;
		#define ck(x) (x>=mod?x-mod:x)
		#define update(x,y) x=ck(x+y)
		for(int i=1;i<=n;++i){
			for(int j=0;j<=i/C;++j)memset(dp[i&1][j],0,sizeof(int)*(1<<C));
			for(int j=0;j<=i/C;++j){
				for(int k=0;k<all;++k){
					int w=dp[(i-1)&1][j][k];
					if(w){
						update(dp[i&1][j][k],w);
						int s=k|(1<<a[i]);
						if(s==all){
							update(dp[i&1][j+1][0],w);
						}
						else{
							update(dp[i&1][j][s],w);
						}
					}
				}	
			}
		}
		for(int j=0;j<=n;++j){	
			for(int k=0;k<all;++k)ans[j]=ck(ans[j]+dp[n&1][j][k]);	
		}
		ans[0]=(ans[0]+mod-1)%mod;
	}
}
namespace Sol_2{
	int dp[N][N],t[N][N],ipw2[N],pw2[N];
	void Solve(){
		pw2[0]=1;
		for(int i=1;i<=n;++i){
			(pw2[i]=pw2[i-1]<<1)%=mod;
			ipw2[i]=qpow(pw2[i]-1,mod-2);
		}
		for(int i=1;i<=n;++i){
			static int g[N];
			int zero=C;
			for(int j=1;j<=C;++j)g[j]=0;
			int ans=1;
			for(int j=i;j>=1;--j){
				if(!g[a[j]])--zero;
				else ans=1LL*ans*ipw2[g[a[j]]]%mod;
				++g[a[j]];
				t[j][i]=(zero?0:ans);
				ans=1LL*ans*(pw2[g[a[j]]]-1)%mod;	
			}
		}
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			dp[0][i]=pw2[i];
			for(int j=1;j<=i/C;++j){
				for(int k=1;k<=i;++k){
					dp[j][i]=(dp[j][i]+1LL*dp[j-1][k-1]*t[k][i])%mod;	
				}
			}
		}
		for(int j=1;j<=n;++j){
			ans[j]=dp[j][n];
		}
		ans[0]=pw2[n]-1;
		for(int i=0;i<n;++i){
			ans[i]=(ans[i]-ans[i+1]+mod)%mod;
		}	
	}
}
int main(){
	n=read(),C=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(C<=12){
		Sol_1::Solve();	
	}
	else{
		Sol_2::Solve();
	}
	for(int i=0;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}