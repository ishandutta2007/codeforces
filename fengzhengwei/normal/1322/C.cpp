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
set<int>s[500005]; 
map<set<int>,ll>mp;
ll val[500005];
int n;
ll gcd(ll a,ll b)
{
	return !b?a:gcd(b,a%b);
}
int main(){
	int t=read();
	while(t--)
	{
		n=read();int m=read();
		for(int i=1;i<=n;i++)
		{
			s[i].clear();
			val[i]=read();
		}
		mp.clear();
		for(int i=1;i<=m;i++)
		{
			int a,b;
			a=read();
			b=read();s[b].insert(a);
		}
		for(int i=1;i<=n;i++)if(s[i].size())mp[s[i]]+=val[i];
		ll ans=0;
		for(map<set<int>,ll>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(!ans)ans=(*it).second;
			else ans=gcd(ans,(*it).second);
		}
		cout<<ans<<endl;
	}
	return 0;
}