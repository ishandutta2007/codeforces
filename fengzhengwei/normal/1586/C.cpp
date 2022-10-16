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
const int xx=1e6+5;
vector<vector<int> >v;
int vis[xx];
signed main(){
	int n=read(),m=read();
	v.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		v[i].resize(m+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			while((c=getchar())!='.'&&c!='X');
			if(c=='X')v[i][j]=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=1&&j!=m&&v[i][j]&&v[i-1][j+1])vis[j]=1;
		}
	}
	for(int j=1;j<=m;j++)vis[j]+=vis[j-1];
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		if(!(vis[r-1]-vis[l-1]))
		{
			puts("YES");
		}
		else 
		{
			puts("NO");
		}
	}
	return 0;
}