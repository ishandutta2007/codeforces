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
int T;
int a[505][505];
int b[505][505];
int vis[250005];
int n,m;
void check(int x)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][1]==b[x][i])
			{
				for(int w=1;w<=m;w++)
				{
					printf("%d ",a[j][w]);
				}
				puts("");
				break;
			}
		}
	}
}
int main(){
	T=read();
	while(T--)
	{
		n=read();
		m=read();
		for(int i=1;i<=n*m;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=read();
		for(int i=1;i<=n;i++)
		{
			vis[a[i][1]]=1;
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				b[i][j]=read();
		for(int i=1;i<=m;i++)
		{
			int viss=1;
			for(int j=1;j<=n;j++)
			{
				if(!vis[b[i][j]])
				{
					viss=0;break;
				}
			}
			if(viss)
			{
				check(i);
				break;
			}
		}
	}
	return 0;
}