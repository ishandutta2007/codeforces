#include<bits/stdc++.h>
#define ll long long
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
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
ll lcm[45];
const int mod=1e9+7;
int main(){
	int T=read();
	while(T--)
	{
		ll res=1;
		for(int i=1;i<=41;i++)res=res/gcd(res,i)*i,lcm[i]=res;
		ll n=read();
		ll rem=0;
		ll ans=0;
		for(int i=41;i>=1;i--)
		{
			ans+=(i+1)*(n/lcm[i]-rem);
			ans%=mod;
			rem=n/lcm[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}