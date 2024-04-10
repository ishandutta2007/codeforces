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
const int xx=1e5+5;
char s[xx];
int n,m;
bool check(int x)
{
	if(x==1||x==n)return 0;
	if(x==0||x==n+1)return 0;
	if(s[x-1]=='a'&&s[x]=='b'&&s[x+1]=='c')return 1;
	return 0;
}
signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	int rans=0;
	for(int i=1;i<=n;i++)rans+=check(i);
	while(m--)
	{
		int a=read();
		char c;
		while((c=getchar())!='a'&&c!='b'&&c!='c');
		rans-=check(a-1);
		rans-=check(a);
		rans-=check(a+1);
		
		s[a]=c;
		
		rans+=check(a-1);
		rans+=check(a);
		rans+=check(a+1);
		
		cout<<rans<<"\n";
	}
	pc('1',1);
	return 0;
}