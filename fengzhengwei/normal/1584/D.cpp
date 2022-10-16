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
const int xx=1e5+5;
ll qu(ll a,ll b)
{
	cout<<"? "<<a<<" "<<b<<"\n";
	fflush(stdout);
	return read();
}
signed main(){
	int T=read();
	while(T--)
	{
		ll n=read();
		ll sum=qu(1,n);
		ll l=1,r=n;
		while(l<=r)
		{
			ll mid=l+r>>1;
			ll a=qu(1,mid);
			if(a==0)l=mid+1;
			else if(a==sum)r=mid-1;
			else 
			{
				ll dlt=a-qu(1,mid-1);
				ll L=mid-dlt;//30 
				if(qu(1,L)==0)//i 
				{
					ll i=L;
					ll dlt1=qu(L,n)-qu(L+1,n);
					ll j=i+dlt1+1;
					dlt1=qu(j,n)-qu(j+1,n);
					ll k=j+dlt1;
					cout<<"! "<<i<<" "<<j<<" "<<k<<"\n";
					fflush(stdout);
					break;
				}
				else //j 
				{
					ll j=L;
					ll dlt1=qu(j,n)-qu(j+1,n);
					ll k=j+dlt1;
					dlt1=qu(1,j-1)-qu(1,j-2);
					ll i=j-1-dlt1;
					cout<<"! "<<i<<" "<<j<<" "<<k<<"\n";
					fflush(stdout);
					break;
				}
			}
		}
	}
	pc('1',1);
	return 0;
}