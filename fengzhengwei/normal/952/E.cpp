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
int n;
signed main(){
	n=read();
	int tt1=0,tt2=0;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		if(b=="soft")tt1++;
		else tt2++;
	}
	for(int i=1;;i++)
	{
		int a=i*i/2,b=i*i-a;
		if(a>=tt1&&b>=tt2)cout<<i<<"\n",exit(0);
		if(a>=tt2&&b>=tt1)cout<<i<<"\n",exit(0);
	}
	pc('1',1);
	return 0;
}