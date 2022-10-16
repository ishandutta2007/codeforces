#include<bits/stdc++.h>
#define ll long long
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
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1000;
int T;
ll a[xx];
signed main(){
	T=read();
	while(T--)
	{
		int n=read();
		int res=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			while(a[i]%2==0)a[i]/=2,res++;
		}
		int mx=0;
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			mx=max(mx,(int)a[i]);
		}
		ll re=mx;
		while(res--)re*=2;
		sum-=mx;
		sum+=re;
		cout<<sum<<"\n";
	}
	pc('1',1);
	return 0;
}