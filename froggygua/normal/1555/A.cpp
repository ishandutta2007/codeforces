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
ll n;
int main(){
	T=read();
	while(T--){
		n=read();
		ll ans=1e18;
		for(int i=0;i<=120;++i){
			for(int j=0;j<=min(120LL,(n-i*8+7)/6);++j){
				ll k=max(0LL,(n-i*8-j*6+9)/10);
				ans=min(ans,k*25+i*20+j*15);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}