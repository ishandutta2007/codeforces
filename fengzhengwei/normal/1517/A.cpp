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

signed main(){
	int T=read();
	while(T--)
	{
		ll a;
		a=read();
		if(a%2050!=0)
		{
			puts("-1");
			continue;
		}
		ll s=a/2050;
		int res=0;
		while(s)
		{
			res+=s%10;
			s/=10;
		}
		cout<<res<<"\n";
	}
	return 0;
}