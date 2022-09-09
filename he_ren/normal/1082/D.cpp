#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 5e2 + 5;

struct Node
{
	int x,id;
}a[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x>q.x;}
int tot[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].x), a[i].id=i;
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
		++tot[a[i].x];
	if(tot[1]<2)
	{
		printf("YES %d\n%d\n",n-1,n-1);
		for(int i=1; i<n; ++i) printf("%d %d\n",a[i].id,a[i+1].id);
		return 0;
	}
	
	int cnt=0;
	for(int i=2; i<n; ++i)
		cnt += (i-2)*tot[i];
	if(cnt < tot[1]-2){ printf("NO"); return 0;}
	printf("YES %d\n%d\n", n-(tot[1]-2)-1, n-1);
	
	for(int i=1; i<n; ++i)
	{
		if(!a[i].x)
		{
			printf("%d %d\n",a[i+1].id,a[1].id);
			--a[i+1].x; --a[1].x;
			break;
		}
		printf("%d %d\n",a[i].id,a[i+1].id);
		--a[i].x; --a[i+1].x;
	}
	for(int i=n-(tot[1]-2)+1,j=1; i<=n; ++i)
	{
		while(j<=n && !a[j].x) ++j;
		printf("%d %d\n",a[i].id,a[j].id);
		--a[j].x; --a[i].x;
	}
	return 0;
}