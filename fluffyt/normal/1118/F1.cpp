#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,tot,sum1,sum2,ans;
int point[1000005],nxt[1000005],head[1000005];
int col[1000005],f1[1000005],f2[1000005];
void addedge(int x,int y)
{
	point[++tot]=y,nxt[tot]=head[x],head[x]=tot;
	point[++tot]=x,nxt[tot]=head[y],head[y]=tot;
}
void dfs(int x,int fa)
{
	f1[x]=(col[x]==1);
	f2[x]=(col[x]==2);
	for(int i=head[x];i;i=nxt[i])
	{
		int y=point[i];
		if(y==fa) continue;
		dfs(y,x);
		if((f1[y]&&f2[y])||((sum1-f1[y])&&(sum2-f2[y]))) ans--;
		f1[x]+=f1[y],f2[x]+=f2[y];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&col[i]);
		sum1+=(col[i]==1);
		sum2+=(col[i]==2);
	}
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	ans=n-1;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}