#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
struct Edge {int y,ne;};
int n,num;
Edge e[N*2];int last[N];
int c[N],leg[N],del[N];
void dfs(int i,int fa)
{
	if (c[i]<=2)
	{
		del[i]=1;
		for (int j=last[i];j;j=e[j].ne)
		if (e[j].y!=fa) dfs(e[j].y,i);
	}
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		c[x]++;c[y]++;
	}
	for (int i=1;i<=n;i++)
		if (c[i]==1) dfs(i,0);
	for (int i=1;i<=n;i++)
	for (int j=last[i];j;j=e[j].ne)
	if (del[e[j].y])
		leg[i]=min(leg[i]+1,2);
	for (int i=1;i<=n;i++)
	if (!del[i])
	{
		int cnt=0;
		for (int j=last[i];j;j=e[j].ne)
		if (!del[e[j].y]&&c[e[j].y]-leg[e[j].y]>1) cnt++;
		if (cnt>2)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}