#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int n,m;
const int xx=505;
int hs[xx][xx],f[xx][xx],v[xx];
signed main(){
	memset(f,0x3f,sizeof(f));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		hs[a][b]=c;
		hs[b][a]=c;
		f[a][b]=min(f[a][b],c),f[b][a]=min(f[b][a],c);
	}
	for(int k=1;k<=n;k++)f[k][k]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)
		{
			v[i]=0;
			for(int j=1;j<=n;j++)if(hs[j][i]&&f[x][j]+hs[j][i]==f[x][i])v[i]++;
		}
		for(int y=x+1;y<=n;y++)
		{
			int ans=0;
			for(int i=1;i<=n;i++)if(f[x][i]+f[i][y]==f[x][y])ans+=v[i];
			cout<<ans<<" ";
		}
		
	}
	puts("");
	return 0;
}