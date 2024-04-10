#include<bits/stdc++.h>
#define ll __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int T,n;
// 
ll a[xx];
ll abs(ll a){return a<0?-a:a;}
ll get(ll t)
{
	ll ans=0;
	if(t>=0)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=0)
				ans+=a[1]*a[i]+t*(a[i]+a[1]);
			else if(abs(t)>=abs(a[i]))
				ans+=a[1]*a[i]+t*(a[i]+a[1]);
			else 
				ans+=a[n]*a[i]+t*(a[i]+a[n]);
		}
	}
	else 
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]<=0)
				ans+=a[n]*a[i]+t*(a[i]+a[n]);
			else if(abs(t)>=abs(a[i]))
				ans+=a[n]*a[i]+t*(a[i]+a[n]);
			else 
				ans+=a[1]*a[i]+t*(a[i]+a[1]);
		}
	}
	return ans;
}
signed main(){
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int is0=0,is1=0,is_0=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<0)is0=1;
			if(a[i]>0)is1=1;
			if(a[i]!=0)is_0=1;
		}
		if(!is_0)
		{
			cout<<0<<"\n";
			continue;
		}
		if(!is0||!is1)
		{
			puts("INF");
			continue;
		}
		sort(a+1,a+n+1);
		ll ans=-1e30,l=-1e12,r=1e12;
		while(l<=r)
		{
			ll lmid=l+(r-l)/3,rmid=l+(r-l)/3+(r-l)/3;
			ll v1=get(lmid),v2=get(rmid);
			if(v1>v2)ans=max(ans,v1),r=rmid-1;
			else ans=max(ans,v2),l=lmid+1;
		}
		if(ans>0)puts("INF");
		else wts(ans,'\n');
		pc('1',1);
		
	}
	pc('1',1);
	return 0;
}