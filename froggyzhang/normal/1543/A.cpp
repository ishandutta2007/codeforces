#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll n,m;
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		if(n==m){
			printf("0 0\n");
			continue;
		}
		ll t=llabs(n-m);
		printf("%lld %lld\n",t,min(n%t,(t-n%t)%t));
	}
	return 0;
}