#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int get(ll a,int b)
{
	int o=0;
	while(a%b==0)o++,a/=b;
	return o;
}
ll pw(ll a,int b)
{
	ll ans=1;
	for(int i=1;i<=b;i++)ans*=a;
	return ans;
}
int T;
signed main(){
	T=read();
	while(T--)
	{
		ll a=read(),b=read();
		if(a%b!=0){cout<<a<<"\n";continue;}
		ll ans=0;
		for(int i=2;i*i<=b;i++)
		{
			if(b%i==0)
			{
				int now=0,ns=0;
				while(b%i==0)now++,b/=i;
				ns=get(a,i);
				ans=max(ans,a/pw(i,ns-now+1));
			}
		}
		if(b!=1)
		{
			int i=b;
			int now=0,ns=0;
			while(b%i==0)now++,b/=i;
			ns=get(a,i);
			ans=max(ans,a/pw(i,ns-now+1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}