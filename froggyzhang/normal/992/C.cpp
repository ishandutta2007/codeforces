#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
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
ll n,k;
int qpow(int a,ll b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),k=read();
	if(!n)return !printf("0\n");
	printf("%lld\n",(n%mod*qpow(2,k+1)-qpow(2,k)+1+mod)%mod);
	return 0;
}