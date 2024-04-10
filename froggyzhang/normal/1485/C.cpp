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
int T;
int main(){
	T=read();
	while(T--){
		int n=read(),m=read();
		int l=2,r=0;
		ll ans=0;
		ans=0;
		for(;l<=m+1;++l){
			if(n/l<=l-2)break;
			ans+=l-2;
		}
		if(l<=n){
			for(;l<=n&&l<=m+1;l=r+1){
				r=min(m+1,n/(n/l));
				ans+=1LL*(n/l)*(r-l+1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}