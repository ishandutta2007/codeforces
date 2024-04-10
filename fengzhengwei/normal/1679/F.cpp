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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=5e4+5,mod=998244353;
int n,m,to[xx],u[xx];
int f[xx][1025];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		u[a]|=(1<<b),u[b]|=(1<<a);
		if(a>b)to[a]|=(1<<b);
		else to[b]|=(1<<a);
	}
	for(int j=0;j<=9;j++)f[1][(1<<j)]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<1024;j++)
		{
			if(f[i][j])
			for(int k=0;k<10;k++)
			{
				if(to[k]&j)continue;
				ad(f[i+1][(j&u[k])|(1<<k)],f[i][j]);
			}
		}
	}
	int ans=0;
	for(int j=0;j<1024;j++)
		ad(ans,f[n][j]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}