#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;

struct Node
{
	int x,pos;
}a[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x==q.x? p.pos<q.pos: p.x>q.x;}
inline bool cmp_pos(const Node &p,const Node &q){ return p.pos<q.pos;}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].x), a[i].pos=i;
	
	sort(a+1,a+n+1,cmp);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int d,pos;
		scanf("%d%d",&d,&pos);
		
		sort(a+1,a+d+1,cmp_pos);
		printf("%d\n",a[pos].x);
		sort(a+1,a+d+1,cmp);
	}
	return 0;
}