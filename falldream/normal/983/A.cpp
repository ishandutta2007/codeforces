#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll mul(ll x,ll mod){return ((x*x-(ll)((long double)x*x/mod)*mod)%mod+mod)%mod;}
int main()
{
	for(int T=read();T;--T)
	{
		ll p=read(),q=read(),b=read();
		q/=gcd(p,q);b%=q;
		for(int i=1;i<=6&&b;++i) b=mul(b,q);
		puts(b?"Infinite":"Finite");
	}
	return 0;
}