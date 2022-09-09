#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

struct Node
{
	int x,y;
	inline friend bool operator < (const Node &p,const Node &q){ return p.y<q.y;}
}a[MAXN];
inline bool cmpX(const Node &p,const Node &q){ return p.x<q.x;}

priority_queue<Node> q;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i].x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i].y);
	
	sort(a+1,a+n+1,cmpX);
	a[n+1].x = 0x3f3f3f3f;
	
	ll sum=0,ans=0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j].x==a[i].x)
		{
			q.push(a[j]);
			sum+=a[j].y;
			++j;
		}
		
		int now = a[i].x;
		while(!q.empty() && now<a[j].x)
		{
			sum-=q.top().y;
			q.pop();
			ans+=sum;
			++now;
		}
	}
	printf("%lld",ans);
	return 0;
}