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
ll n,k;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		printf("%lld\n",(1LL*(n+k-1)/k*k+(n-1))/n);
	}
	return 0;
}