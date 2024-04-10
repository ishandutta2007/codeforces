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
inline bool check(ll x){
	ll tp=x,s=0;
	while(tp)s+=tp%10,tp/=10;
	return __gcd(x,s)>1;	
}
int main(){
	T=read();
	while(T--){
		n=read();
		while(!check(n))++n;
		printf("%lld\n",n);
	}
	return 0;
}