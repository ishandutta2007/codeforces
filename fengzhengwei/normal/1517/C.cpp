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
int n;
const int xx=505;
int ans[xx][xx];
int rem[xx];
pair<int,int>l[xx];
int vis[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)rem[i]=n-i+1;
	for(int i=1;i<=n;i++)
	{
		int a=read(),now=a;
		int nx=i,ny=i;
		memset(vis,0,sizeof(vis));
		memset(l,0,sizeof(l));
		while(now)
		{
			ans[nx][ny]=a;rem[nx]--;
			if(!vis[nx])vis[nx]=1,l[nx]=make_pair(nx,ny);
			if(nx!=1&&ans[nx-1][ny]==0)nx--;
			else if(ny!=n&&ans[nx][ny+1]==0)ny++;
			else 
			{
				while(!rem[nx])nx++;
				ny=l[nx].second+1;
			}
			now--;
		}
	}
		for(int j=1;j<=n;j++)
	{
	for(int i=1;i<=n;i++)
		{
			if(ans[i][j])
			cout<<ans[i][j]<<" ";
		}
		puts("");
	}
	return 0;
}