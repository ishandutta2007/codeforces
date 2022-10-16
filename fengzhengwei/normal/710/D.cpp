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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	ll X=y,Y=x-(a/b)*y;
	x=X,y=Y;
}
signed main(){
	ll a1=read(),b1=read(),a2=read(),b2=read(),l=read(),r=read();
	if((b1-b2)%gcd(a1,a2))
	{
		puts("0");
		return 0;
	}
	ll x,y;
	exgcd(a1,-a2,x,y);
	ll d=gcd(a1,-a2);
	x*=(b2-b1)/d;
	y*=(b2-b1)/d;
//	cout<<a2<<" "<<d<<" "<<" "<<x<<" "<<y<<" "<<x*a1+b1<<" "<<y*a2+b2<<" "<<x*a1-y*a2<<" "<<b2-b1<<"\n";
	ll mn=(x%abs(a2/d)+abs(a2/d))%abs(a2/d);//k1 
//	cout<<mn*a1+b1<<" "<<(-(b2-b1-(mn*a1))/a2)*a2+b2<<"\n";
	l-=b1,r-=b1;
	l=max(l,mn*a1);
	ll mn1=(y%abs(a1/d)+abs(a1/d))%abs(a1/d);//k2 
	ll mx=(b2-b1+mn1*a2)/a1;
	l=max(l,mx*a1);// 
	mn*=a1;
//	cout<<mx<<" "<<mn1<<" "<<mx*a1+b1<<" "<<mn1*a2+b2<<" "<<mn<<" "<<a1*mn+b1<<" "<<x<<" "<<l<<" "<<r<<" "<<a1*a2/d<<"\n";
	if(l>r)puts("0"),exit(0);
	l-=mn,r-=mn;
	
	cout<<(ll)(r/(a1/abs(d)*a2)-floor(1.0*(l-1)/(a1/abs(d)*a2)))<<"\n";
	pc('1',1);
	return 0;
}
//19.09~19.14