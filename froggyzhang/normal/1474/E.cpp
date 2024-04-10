#include<bits/stdc++.h>
using namespace std;
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
int T,n;
void Solve(){
	ll ans=0;
	for(int i=n/2+1;i<=n-1;++i){
		ans+=1LL*(i-1)*(i-1);
	}
	for(int i=1;i<=n/2;++i){
		ans+=1LL*(n-i)*(n-i);
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d ",i==1?n/2+1:(i==n?n/2:(i<=n/2?i-1:i+1)));	
	}
	printf("\n%d\n",n-1);
	for(int i=1;i<=(n-1)/2;++i){
		printf("%d %d\n",n/2+i,1);
	}
	for(int i=n/2;i>=1;--i){
		printf("%d %d\n",i,n);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}