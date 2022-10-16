#include<bits/stdc++.h>
#define int long long
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
const int xx=1e7+5;
bitset<xx>vis;
int prim[xx/10],ct[xx/10],cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			vis[prim[j]*i]=1;
			if(i%prim[j]==0)break;
		}
	}
}
int t[xx],val[xx];
int get(int a,int b){if(b<a)return 0;return get(a,b/a)+b/a;}
signed main(){
	pre(1e7);
	ll res=0;
	n=read();
	ll sm=0;
	for(int i=1;i<=n;i++)
	{
		ll p=read();
		t[p]++;sm+=p;
	}
	for(int i=1e7-1;i>=1;i--)t[i]+=t[i+1];
	for(int i=1;i<=cnt;i++)
	{
		ll x=prim[i];
		while(x<1e7)
		{
//			cout<<x<<"\n";
			for(int j=x;j<=1e7;j+=x)val[j]++;
			x*=prim[i];
		}
		x=prim[i];
		for(int j=x;j<=1e7;j+=x)ct[i]+=val[j]*t[j],val[j]=0;
	}
	ll last=1;
	for(int i=1;i<=cnt;i++)
	{
		if(!ct[i])continue;
//		cout<<i<<" "<<ct[i]<<"\n";
		ll l=last,r=sm,ans=last;
		while(l<=r)
		{
			ll mid=l+r>>1;
			if(get(prim[i],mid)>=ct[i])ans=mid,r=mid-1;
			else l=mid+1;
		}
		last=ans;
	}
	cout<<last<<"\n";
	return 0;
}