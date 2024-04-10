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
int a[55][55];
int dx[]={1,0,-1,0,-1,1,-1,1},dy[]={0,1,0,-1,1,-1,-1,1};
signed main(){
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		int n,m;
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1||j==1||i==n||j==m)
				{
					int vs=0;
					for(int k=0;k<8;k++)
					{
						if(a[i+dx[k]][j+dy[k]])vs=1;
					}
					if(!vs)a[i][j]=1,cout<<'1';
					else cout<<"0";
				}
				else cout<<'0';
			}
			puts("");
		}
		puts("");
	}
	return 0;
}