#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

struct Point
{
	int x,y;
	inline Point operator - (const Point &q){ return (Point){x-q.x,y-q.y};}
}a[MAXN];

typedef Point Vec;


int main(void)
{
	int n;
	scanf("%d",&n);
	if(n&1){ printf("NO"); return 0;}
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	a[n+1]=a[1];
	
	for(int i=1; i<=(n>>1); ++i)
	{
		Vec v = a[i] - a[i+1];
		Vec w = a[i+(n>>1)+1] - a[i+(n>>1)];
		if(v.x!=w.x || v.y!=w.y){ printf("NO"); return 0;}
	}
	printf("YES");
	return 0;
}