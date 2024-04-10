#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll a,b,c,l;
ll C(ll n,ll m)
{
	ll ans=1;
	for(int i=1;i<=m;i++)ans*=n-i+1;
	for(int i=1;i<=m;i++)ans/=i;
	return ans;
}
ll mul(ll x){return x*(x+1)/2;}
int main(){
	a=read(),b=read(),c=read(),l=read();
	ll ans=0;
	for(int i=0;i<=l;i++)ans+=C(i+3-1,3-1);
	for(int i=0;i<=l;i++)
	{
		if(a+i<b+c)continue;
		ans-=mul(min(l-i,a+i-b-c)+1);
//		cout<<ans<<" "<<min(l-i,a+i-b-c)<<'\n';
	}
	swap(a,b);
	for(int i=0;i<=l;i++)
	{
		if(a+i<b+c)continue;
		ans-=mul(min(l-i,a+i-b-c)+1);
	}
	swap(a,c);
	for(int i=0;i<=l;i++)
	{
		if(a+i<b+c)continue;
		ans-=mul(min(l-i,a+i-b-c)+1);
	}
	cout<<ans<<"\n";
	return 0;
}