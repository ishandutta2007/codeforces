#include<cstdio>
#include<algorithm>
#include<queue> 
using namespace std;
struct node
{
	int to;
	int val;
	int nxt;
}edge[400005];
int n,m,k,st,a[200005],head[200005],dis[200005],cnt,ans1,ans2;
int from[200005],to[200005],_cnt[200005];
bool vis[200005];
priority_queue<pair<int,int> > q;
void add(int x,int y,int val)
{
	edge[++cnt].to=y;
	edge[cnt].val=val;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&from[i],&to[i]);
		add(to[i],from[i],1);
	} 
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
	}
	st=a[k];
	for(int i=1;i<=n;i++) dis[i]=1e9;
	q.push(make_pair(0,st));
	dis[st]=0;
	while(!q.empty())
	{
		int tmp=q.top().second;
		q.pop();
		if(vis[tmp]) continue;
		vis[tmp]=true;
		for(int i=head[tmp];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(dis[tmp]+edge[i].val<dis[to])
			{
				dis[to]=dis[tmp]+edge[i].val;
				q.push(make_pair(-dis[to],to));
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(dis[from[i]]==dis[to[i]]+1) _cnt[from[i]]++;
	}
	for(int i=1;i<=k-1;i++)
	{
		if(dis[a[i]]==dis[a[i+1]]+1 && _cnt[a[i]]>=2) 
		{
			ans2++;
		}
		else if(dis[a[i]]!=dis[a[i+1]]+1)
		{
			ans1++;
			ans2++;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}