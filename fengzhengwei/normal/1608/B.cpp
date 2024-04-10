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
int T;
signed main(){
	T=read();
	while(T--)
	{
		int n=read(),a=read(),b=read();
		if(a+b>n-2)
		{
			puts("-1");
			continue;
		}
		if(abs(a-b)>1)
		{
			puts("-1");
			continue;
		}
		if(a==b)
		{
			int l=1,r=n;
			for(int i=1;i<=n;i++)
			{
				if(i&1)cout<<(l++)<<" ";
				else cout<<(r--)<<" ";
				if(i!=1&&(!(i&1)))
					a--;
				if(i!=1&&(i&1))
					b--;
				if(!a&&!b)
				{
					if(i&1)
					{
						while(l<=r)cout<<(l++)<<" ";
						puts("");
						break;
					}
					else 
					{
						while(l<=r)cout<<(r--)<<" ";
						puts("");
						break;
					}
				}
			}
			continue;
		}
		if(a>b)
		{
			int l=1,r=n;
			for(int i=1;i<=n;i++)
			{
				if(i&1)cout<<(l++)<<" ";
				else cout<<(r--)<<" ";
				if(i!=1&&(!(i&1)))
					a--;
				if(i!=1&&(i&1))
					b--;
				if(!a&&!b)
				{
					if(i&1)
					{
						while(l<=r)cout<<(l++)<<" ";
						puts("");
						break;
					}
					else 
					{
						while(l<=r)cout<<(r--)<<" ";
						puts("");
						break;
					}
				}
			}
			continue;
		}
		if(b>a)
		{
			int l=1,r=n;
			for(int i=1;i<=n;i++)
			{
				if(i&1)cout<<n-(l++)+1<<" ";
				else cout<<n-(r--)+1<<" ";
				if(i!=1&&(!(i&1)))
					b--;
				if(i!=1&&(i&1))
					a--;
				if(!a&&!b)
				{
					if(i&1)
					{
						while(l<=r)cout<<n-(l++)+1<<" ";
						puts("");
						break;
					}
					else 
					{
						while(l<=r)cout<<n-(r--)+1<<" ";
						puts("");
						break;
					}
				}
			}
			continue;
		}
	}
	pc('1',1);
	return 0;
}