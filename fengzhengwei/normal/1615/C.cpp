#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
const int xx=2e5+5;
char s[xx],c[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		scanf("%s",c+1);
		int vs=1;
		for(int i=1;i<=n;i++)
			if(s[i]!=c[i])vs=0;
		if(vs)
		{
			puts("0");
			continue;
		}
		int ct0=0,ct1=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=c[i])
			{
				ct0+=(s[i]=='0');
				ct1+=(s[i]=='1');
			}
		}
		int ans=1e9;
		if(ct0==ct1)
			ans=min(ans,ct0+ct1);
		ct0=0,ct1=0;
		
		for(int i=1;i<=n;i++)
		{
			if(s[i]==c[i])
			{
				ct0+=(s[i]=='0');
				ct1+=(s[i]=='1');
			}
		}
		if(ct0+1==ct1)
			ans=min(ans,ct0+ct1);
		if(ans==1e9)
		{
			puts("-1");
		}
		else cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}