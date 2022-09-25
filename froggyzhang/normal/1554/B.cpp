#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,K,n,a[N];
void Solve(){
	n=read(),K=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ll ans=-1e18;
	for(int i=n;i>=1;--i){
		for(int j=i-1;j>=1;--j){
			if(1LL*i*j<=ans)break;
			ans=max(ans,1LL*i*j-1LL*K*(a[i]|a[j]));	
		}		
	}
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}