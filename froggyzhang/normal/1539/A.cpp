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
int T,n,x,t;
int main(){
	T=read();
	while(T--){
		n=read(),x=read(),t=read();
		int z=min(n-1,t/x);
		printf("%lld\n",1LL*z*(z+1)/2+1LL*z*(n-z-1));
	}
	return 0;
}