#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Node
{
	int x,y;
	inline int area(void){ return x*y;}
}a[MAXN];

int main(void)
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			for(int k=0; k<4; ++k)
			{
				Node p=a[i], q=a[j];
				if(k&1) swap(p.x,p.y);
				if(k&2) swap(q.x,q.y);
				
				if(p.x>x || p.y>y || q.x>x || q.y>y) continue;
				
				if(p.x+q.x <= x || p.y+q.y <= y)
					chk_max( ans, p.area()+q.area() );
			}
		}
	printf("%d",ans);
	return 0;
}