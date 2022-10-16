#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=505;
int n,m,t;
ll f[xx][xx][25];// 
int v[xx][xx][4];//0,1,2,3 
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
signed main(){
//	cout<<sizeof(f)/1024/1024<<"\n";
	n=read();
	m=read();
	t=read();
	if(t&1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<"-1 ";
			}
			puts("");
		}
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)f[i][j][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			v[i][j][3]=v[i][j+1][2]=read();
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			v[i][j][1]=v[i+1][j][0]=read();
		}
	}
	for(int k=1;k<=t/2;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int w=0;w<4;w++)
				{
					int tx=i+dx[w],ty=j+dy[w];
					if(tx<1||ty<1||tx>n||ty>m)continue;
					f[i][j][k]=min(f[i][j][k],f[tx][ty][k-1]+v[i][j][w]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<f[i][j][t/2]*2<<" ";
		}
		puts("");
	}
	return 0;
}