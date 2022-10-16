#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=105;
int n,m,a[xx][xx],b[xx][xx];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j])
			{
				for(int k=1;k<=m;k++)b[i][k]=0;
				for(int k=1;k<=n;k++)b[k][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int res=0;
			for(int k=1;k<=m;k++)res|=b[i][k];
			for(int k=1;k<=n;k++)res|=b[k][j];
			if(res!=a[i][j])puts("NO"),exit(0);
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<b[i][j]<<" ";
		puts("");
	}
	return 0;
}