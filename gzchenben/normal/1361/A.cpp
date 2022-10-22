#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int x,id;
}a[500005];
bool cmp(node x,node y)
{
	return x.x<y.x;
}
int n,m,cnt[500005],t[500005];
vector<int> vec[500005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=a[i].id;
		for(int j=0;j<vec[x].size();j++)
		{
			cnt[t[vec[x][j]]]=true;
		}
		int tmp=1;
		while(cnt[tmp]) tmp++;
		t[x]=tmp;
		for(int j=0;j<vec[x].size();j++)
		{
			cnt[t[vec[x][j]]]=false;
		}
		if(t[x]!=a[i].x) 
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].id);
	}
	printf("\n");
}