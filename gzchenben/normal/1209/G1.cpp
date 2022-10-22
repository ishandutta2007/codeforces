#include<cstdio>
#include<algorithm>
#define INF 100000000
using namespace std;
struct node
{
	int minn;
	int maxn;
	int size;
}a[200005];
bool cmp(node x,node y)
{
	return x.minn<y.minn;
}
int n,m,now=0,ans,last=1;
int main()
{
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=1;i<=200000;i++)
	{
		a[i].minn=INF;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x].minn=min(a[x].minn,i);
		a[x].maxn=max(a[x].maxn,i);
		a[x].size++;
	}
	sort(a+1,a+200001,cmp);
//	printf("%d %d %d\n",a[1].minn,a[1].maxn,a[1].size);
	while(now!=n)
	{
//		printf("%d ",now);
		int max_size=0;
		now++;
//		printf("%d ",now);
		for(int i=last;i<=n;i++)
		{
			if(a[i].minn<=now)
			{
				now=max(now,a[i].maxn);
//				printf("%d ",i);
				max_size=max(max_size,a[i].size);
			}
			else
			{
				last=i;
				break; 
			}
		}
//		printf("\n");
		ans-=max_size;
	}
	printf("%d\n",ans);
	return 0;
}