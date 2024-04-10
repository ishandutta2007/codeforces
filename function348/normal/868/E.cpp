#include<iostream>
#include<cstdio>
using namespace std;
const int N=60;
typedef long long LL;
struct Edge {int x,y,z,ne;};
Edge e[N*2];int last[N];
int n,m,st;
int s[N],fa[N],d[N];
int f[N*2][N][N];
void dfs(int i)
{
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa[i])
	{
		fa[e[j].y]=i;
		dfs(e[j].y);
		s[i]+=s[e[j].y];
	}
}
int dp(int p,int a,int b)
{
	if (f[p][a][b]!=0) return f[p][a][b];
	if (a==0) return 0;
	if (b==0) return 130000;
	if (d[e[p].y]==1) return dp(p^1,a-b,a-b)+e[p].z;
	f[p][a][0]=130000;
	for (int j=last[e[p].y];j;j=e[j].ne)
	if ((j^p)!=1) dp(j,a,a);
	for (int j=last[e[p].y];j;j=e[j].ne)
	if ((j^p)!=1)
	{
		for (int i=a;i>=0;i--)
		for (int k=1;i+k<=a;k++)
			f[p][a][i+k]=max(f[p][a][i+k],min(f[p][a][i],dp(j,a,k)));
	}
	for (int i=1;i<=a;i++) 
	{
		f[p][a][i]+=e[p].z;
//		printf("%d %d %d %d\n",p,a,i,f[p][a][i]);
	}
	return f[p][a][b];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i*2]=(Edge){x,y,z,last[x]};last[x]=i*2;
		e[i*2+1]=(Edge){y,x,z,last[y]};last[y]=i*2+1;
		d[x]++,d[y]++;
	}
	scanf("%d",&st);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		s[x]++;
	}
	dfs(1);
	int ans=130000;
	for (int j=last[st];j;j=e[j].ne)
	{
		if (e[j].x==fa[e[j].y])
		ans=min(ans,dp(j,m,s[e[j].y]));
		else ans=min(ans,dp(j,m,m-s[e[j].x]));
	}
	printf("%d\n",ans);
	return 0;
}