#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
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
const int xx=2e5+5;
int a[xx];
int main(){
	int n=read();
	if(n==1)puts("0"),exit(0);
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n%2==0)a[++n]=0;
	multiset<ll>s;
	for(int i=1;i<=n;i++)s.insert(a[i]);
	ll ans=0;
	while(s.size()!=1)
	{
		ll sm=0;
		sm+=*s.begin();
		s.erase(s.begin());
		sm+=*s.begin();
		s.erase(s.begin());
		sm+=*s.begin();
		s.erase(s.begin());
		ans+=sm;
		s.insert(sm);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}