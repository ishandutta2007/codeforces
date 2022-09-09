#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

struct Node
{
	int t,a,b;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.t < q.t;}

void solve(void)
{
	int n,m,c,beg;
	scanf("%d%d%d%d",&n,&m,&c,&beg);
	for(int i=1; i<=n; ++i) scanf("%d%d%d",&p[i].t,&p[i].a,&p[i].b);
	
	sort(p+1,p+n+1,cmp);
	
	map<int,int> cost;
	cost[0] = beg;
	int sum = beg;
	
	p[++n] = (Node){m,0,0};
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int need = p[i].t - p[i-1].t;
		if(sum < need){ printf("-1\n"); return;}
		while(!cost.empty() && need)
		{
			pii cur = *cost.begin();
			cost.erase(cost.begin());
			
			int used = min(cur.second, need);
			ans += (ll)used * cur.first;
			
			need = need - used;
			cur.second -= used;
			sum -= used;
			if(cur.second)
				cost[cur.first] = cur.second;
		}
		
		if(sum < c)
		{
			int tmp = min(p[i].a, c-sum);
			cost[p[i].b] += tmp;
			sum += tmp;
			p[i].a -= tmp;
		}
		while(!cost.empty() && p[i].a)
		{
			pii cur = *cost.rbegin();
			if(cur.first <= p[i].b) break;
			cost.erase(cur.first);
			
			int used = min(cur.second, p[i].a);
			cur.second -= used;
			p[i].a -= used;
			
			cost[p[i].b] += used;
			if(cur.second) cost[cur.first] += cur.second;
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}