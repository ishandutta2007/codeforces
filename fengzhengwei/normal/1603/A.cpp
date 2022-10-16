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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
int n;
const int xx=1e5+5;
int a[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		set<int>s;
		int tt=n;
		for(int i=1;i<=n;i++)if(a[i]%(i+1))s.insert(i);
		while(!s.empty())
		{
			int x=*--s.end();
			s.erase(x);
			for(int i=x;i<=tt-1;i++)
			{
				a[i]=a[i+1];
				if(a[i]%(i+1))s.insert(i);
			}
			tt--;
		}
		if(tt!=0)
		{
			puts("NO");
		}
		else puts("YES");
	}
	return 0;
}