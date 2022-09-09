#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

struct Node
{
	ll hp,dmg,mx;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.hp-p.dmg > q.hp-q.dmg;}

int main(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1; i<=n; ++i)
		scanf("%lld%lld",&p[i].hp,&p[i].dmg),
		p[i].mx = max(p[i].hp, p[i].dmg);
	
	sort(p+1,p+n+1,cmp);
	ll sum=0;
	for(int i=1; i<=b && i<=n; ++i) sum += p[i].mx;
	for(int i=b+1; i<=n; ++i) sum += p[i].dmg;
	
	ll ans=sum;
	for(int i=1; i<=b; ++i)
		chk_max(ans, sum - p[i].mx + max(p[i].dmg, p[i].hp<<a));
	if(b) for(int i=b+1; i<=n; ++i)
		chk_max(ans, sum - p[b].mx + p[b].dmg - p[i].dmg + max(p[i].dmg, p[i].hp<<a));
	printf("%lld",ans);
	return 0;
}