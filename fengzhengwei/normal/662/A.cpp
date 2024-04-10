#include<bits/stdc++.h>
#define ll long long
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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=5e5+5;
ll T,s[68],a[xx],b[xx];
bool in(ll x){for(int i=61;i>=0;i--)if(x>>i&1){if(!s[i])return swap(s[i],x),0;else x^=s[i];}return 1;}
signed main(){
	memset(s,0,sizeof(s));
	int n=read();
	ll sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum^=a[i],b[i]=read();
	int res=0;
	for(int i=1;i<=n;i++)res+=in(a[i]^b[i]);
	if(in(sum))
	{
		if(!sum&&res==n)puts("0/1");
		else cout<<(1ll<<(n-res))-1<<"/"<<(1ll<<(n-res))<<'\n';
	}
	else puts("1/1");
	pc('1',1);
	return 0;
}