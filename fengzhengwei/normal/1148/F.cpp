#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=3e5+5;
struct node
{
	int val,mx;
	ll msk;
}e[xx];
ll s;
signed main(){
//	freopen("a.in","r",stdin);
	n=read();
	ll sm=0;
	for(int i=1;i<=n;i++)
	{
		e[i].val=read(),e[i].msk=read();
		for(int j=62-1;j>=0;j--)
		{
			if(e[i].msk>>j&1)
			{
				e[i].mx=j;
				break;
			}
		}
		sm+=e[i].val;
	}
	if(sm<0)
	{
		sm=-sm;
		for(int i=1;i<=n;i++)e[i].val=-e[i].val;
	}
	for(int i=0;i<62;i++)
	{
		if(s>>i&1)continue;
		ll dlt=0;
		for(int j=1;j<=n;j++)
			if(e[j].mx==i)dlt+=e[j].val;
		if(dlt>0)
		{
			s+=(1ll<<i);
			for(int j=1;j<=n;j++)
				if(e[j].msk>>i&1)e[j].val=-e[j].val;
		}
	}
	cout<<s<<"\n";
    return 0;
}