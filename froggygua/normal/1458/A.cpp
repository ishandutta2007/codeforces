#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,m;
ll a[N],t;
ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=2;i<=n;++i){
		if(a[i]^a[1])t=__gcd(t,Abs(a[i]-a[1]));
	}
	for(int i=1;i<=m;++i){
		ll x=read();
		printf("%lld ",__gcd(a[1]+x,t));
	}
	return 0;
}