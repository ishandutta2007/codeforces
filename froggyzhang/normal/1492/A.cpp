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
ll p,a,b,c;
inline ll z(ll x,ll p){
	return (x-p%x)%x;
}
int main(){
	T=read();
	while(T--){
		p=read(),a=read(),b=read(),c=read();
		printf("%lld\n",min(z(a,p),min(z(b,p),z(c,p))));
	}
	return 0;
}