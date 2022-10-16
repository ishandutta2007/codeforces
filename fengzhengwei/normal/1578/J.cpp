#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int mod=1e9+7;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int main(){
	int n=read(),m=read();
	cout<<1ll*ksm(n+1,m-1)*ksm(2,m)%mod*(n-m+1)%mod<<"\n";
	pc('1',1);
	return 0;
}

}int main(){return ifzw::main();}
/*
#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1005;
int jiec[xx],c[xx][xx],f[xx];
int g[105][105];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i;
	for(int i=0;i<xx;i++)c[i][0]=1;
	for(int i=1;i<xx;i++)
		for(int j=1;j<=i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	int n=100;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			f[i]+=c[i-1][j]*f[j]*f[i-1-j];
		f[i]*=(i+1);
	}
	g[0][0]=1;
	for(int i=1;i<=n;i++)g[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i<j)
			{
				g[i][j]=0;
				continue;
			}
			if(i==j)
			{
				g[i][j]=f[i];
				continue;
			}
			g[i][j]=g[i-1][j];
			for(int k=1;k<=j;k++)
				g[i][j]+=g[i-k-1][j-k]*f[k]*c[j][k];
		}
	}
	for(int i=1;i<=10;i++)
		for(int j=1;j<=i;j++)cout<<g[i][j]<<" \n"[j==i];
	
	pc('1',1);
	return 0;
}
*/