#include<cstdio>
#include<algorithm>
const int MAXN = 100 + 5;
using namespace std;

struct Node
{
	int x,y;
}a[MAXN];
inline bool cmp(Node x,Node y)
{
	if(x.y>=0 && y.y<0) return 1;
	if(x.y<0 && y.y>=0) return 0;
	
	if(x.y>=0)
	{
		if(x.x != y.x)
			return x.x<y.x;
		else return x.y>y.y;
	}
	if(x.x+x.y != y.x+y.y)
		return x.x+x.y > y.x+y.y;
	else if(x.y != y.y) return x.y>y.y;
	else return x.x<y.x;
}

int main(void)
{
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(r+a[i].y < 0) break;
		if(r>=a[i].x)
		{
			++ans;
			r+=a[i].y;
		}
	}
	if(ans==n) printf("YES");
	else printf("NO");
	return 0;
}