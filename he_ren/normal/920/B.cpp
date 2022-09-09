#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 1e3 + 5;
const int m = 5e3;
const int MAXM = m + 5;

struct Node
{
	int l,r,id;
}a[MAXN];
queue<Node> q;
int ans[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].l,&a[i].r), a[i].id=i;
	
	for(int i=1; i<=n; ++i) ans[i]=0;
	for(int i=1,j=1; i<=m; ++i)
	{
		while(j<=n && a[j].l==i)
			q.push(a[j]), ++j;
		while(!q.empty() && q.front().r < i) q.pop();
		if(!q.empty())
		{
			ans[q.front().id]=i;
			q.pop();
		}
	}
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}