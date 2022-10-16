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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int n,m,sum0[xx],sum1[xx];
char s[xx];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)sum0[i]=sum0[i-1]+(s[i]==s[i+1]&&s[i]=='0');
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+(s[i]==s[i+1]&&s[i]=='1');
	while(m--)
	{
		int l=read(),r=read();
		cout<<max(sum1[r-1]-sum1[l-1],sum0[r-1]-sum0[l-1])+1<<"\n";
	}
	pc('1',1);
	return 0;
}