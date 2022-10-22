#include<cstdio>
#include<cstring>
using namespace std;
int t[110000],c[110000][2];
struct node{
	int y,next;
}a[210000];int len,last[110000],d[110000];
int dfn[110000],low[110000],ans2[110000];
int f[110000],size[110000];
int mymin(int x,int y) {return x<y?x:y;}
void ins(int x,int y)
{
	a[++len].y=y;a[len].next=last[x];last[x]=len;
}
int sum=0,tot=0,ans=999999999;
void dfs(int x)
{
	dfn[x]=low[x]=++sum;d[++tot]=x;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(dfn[y]==0) dfs(y);
		low[x]=mymin(low[x],low[y]);
	}
	if(dfn[x]==low[x])
	{
		int sum1=0;
		while(d[tot]!=x)
		{
			f[d[tot]]=x;
			sum1++;tot--;
		}
		tot--;sum1++;size[x]=sum1;f[x]=x;
	}
}
int main()
{
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&c[i][0],&c[i][1]);
		if((t[c[i][0]]+1)%h==t[c[i][1]]) ins(c[i][0],c[i][1]);
		if((t[c[i][1]]+1)%h==t[c[i][0]]) ins(c[i][1],c[i][0]);
	}
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++) if(dfn[i]==0) dfs(i);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		int x=f[c[i][0]],y=f[c[i][1]];
		if(x!=y)
		{
			if((t[c[i][0]]+1)%h==t[c[i][1]]) ins(x,y);
			if((t[c[i][1]]+1)%h==t[c[i][0]]) ins(y,x);
		}
	}
	int ans=999999999,ans2;
	for(int i=1;i<=n;i++) 
	{
		if(f[i]==i&&last[i]==0&&ans>size[i]) ans=size[i],ans2=i;
	}
	printf("%d\n",size[ans2]);
	for(int i=1;i<=n;i++) if(f[i]==ans2) printf("%d\n",i);
	return 0;
}