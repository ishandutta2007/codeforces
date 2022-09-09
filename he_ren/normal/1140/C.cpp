#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

struct Node
{
	int t,b;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.b > q.b;}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].t,&p[i].b);
	
	sort(p+1,p+n+1,cmp);
	
	priority_queue<int,vector<int>,greater<int> > q;
	ll sum = 0, ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i].b == p[j].b) ++j;
		
		for(int k=i; k<j; ++k)
			q.push(p[k].t),
			sum += p[k].t;
		
		while((int)q.size() > d)
			sum -= q.top(),
			q.pop();
		ans = max(ans, sum * p[i].b);
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}