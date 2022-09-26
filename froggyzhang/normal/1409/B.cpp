#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
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
int T,a,b,x,y,n;
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),x=read(),y=read(),n=read();
		ll ans=2e18;
		if(n>=a-x+b-y){
			ans=1LL*x*y;
		}
		else{
			ans=min(ans,n>a-x?1LL*x*(b-(n-(a-x))):1LL*(a-n)*b);
			ans=min(ans,n>b-y?1LL*(a-(n-(b-y)))*y:1LL*a*(b-n));
		}
		printf("%lld\n",ans);
	}
	return 0;
}