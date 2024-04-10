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
int T;
ll m,d,w;
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
ll calc(ll x,ll i){
	ll tot=0;
	ll p=x/i-1;
	tot+=p*(x/i)/2*i;
	tot+=1LL*(x/i)*(x%i+1);
	return tot;
}
int main(){
	T=read();
	while(T--){
		m=read(),d=read(),w=read();
		if(d==1){
			printf("0\n");
			continue;
		}
		w/=_gcd(d-1,w);
		printf("%I64d\n",calc(min(m,d)-1,w));
	}
	return 0;
}