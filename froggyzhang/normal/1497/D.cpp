#include<bits/stdc++.h>
using namespace std;
#define N 5050
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
int T,tag[N],s[N],n;
ll dp[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		tag[i]=read();
	}
	for(int i=1;i<=n;++i){
		s[i]=read();
	}
	ll ans=0;
	dp[1]=0;
	for(int i=2;i<=n;++i){
		dp[i]=0;
		for(int j=i-1;j>=1;--j){
			if(tag[i]^tag[j]){
				ll wi=dp[i],wj=dp[j];
				dp[i]=max(dp[i],wj+abs(s[i]-s[j]));
				dp[j]=max(dp[j],wi+abs(s[i]-s[j]));
			}
		}
	}
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	
	
	return 0;
}