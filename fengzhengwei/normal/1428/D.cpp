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
int a[200005];
int vis[200005];
int revis[200005];
int cnt;
pair<int,int> ans[1000005];
int tot;
int main(){
	n=read();
	tot=n+1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(!a[i])vis[i]=1;
	}
	int z2=1;
	int z1=1;
	for(;z2<=n;z2++)
	{
		if(a[z2]!=2)continue;
		z1=max(z1,z2);
		int viss=0;
		for(;z1<=n;z1++)
		{
			if(a[z1]==1)
			{
				viss=1;
				break;
			}
		}
		if(!viss)break;
		vis[z2]=vis[z1]=1;
		ans[++cnt]=make_pair(--tot,z2);
		ans[++cnt]=make_pair(tot,z1);
		z1++;
	}
	if(z2!=n+1)
	{
		puts("-1");
		return 0;
	}
	int nnn=0;
	z1=1;
	int i=1;
	for(;i<=n;i++)
	{
		if(!vis[i])
		{
			if(a[i]==3)
			{
				z1=max(z1,i+1);
				int viss=0;
				for(;z1<=n;z1++)
				{
					if(a[z1]==2||a[z1]==3||(a[z1]==1&&!vis[z1]))
					{
						viss=1;
						break;
					}
				}
				if(!viss)break;
				ans[++cnt]=make_pair(++nnn,i);
				ans[++cnt]=make_pair(nnn,z1);
				z1++;
			}
		}
	}
	if(i!=n+1)
	{
		puts("-1");
		return 0;
	}
	if(nnn>=tot)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&a[i]==1)
		{
			ans[++cnt]=make_pair(++nnn,i);
		}
	}
	if(nnn>=tot)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}