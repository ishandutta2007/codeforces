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
int a[505][505];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n+n;i++)
			for(int j=1;j<=n+n;j++)a[i][j]=read();
		ll ans=0;
		for(int i=n+1;i<=n+n;i++)
			for(int j=n+1;j<=n+n;j++)ans+=a[i][j];
		int mn=2e9;
		mn=min(mn,a[1][n+1]);
		mn=min(mn,a[1][n+n]);
		mn=min(mn,a[n][n+1]);
		mn=min(mn,a[n][n+n]);
		mn=min(mn,a[n+1][n]);
		mn=min(mn,a[n+1][1]);
		mn=min(mn,a[n+n][1]);
		mn=min(mn,a[n+n][n]);
		cout<<ans+mn<<"\n";
	}
	pc('1',1);
	return 0;
}