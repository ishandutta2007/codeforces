#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXM = 1e5 + 5;

struct Node
{
	int a,b;
}p[MAXM];
inline bool cmp(const Node &p,const Node &q){ return p.a < q.a;}

ll a[MAXM], b[MAXM];
ll sum[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		scanf("%d%d",&p[i].a,&p[i].b);
	
	sort(p+1,p+m+1,cmp);
	for(int i=1; i<=m; ++i)
		a[i] = p[i].a,
		b[i] = p[i].b;
	
	for(int i=1; i<=m; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = 0;
	if(n<=m) ans = sum[m] - sum[m-n];
	
	for(int i=1; i<=m; ++i)
	{
		int pos = upper_bound(a+1,a+m+1, b[i]) - a;
		if(m-pos+1 >= n) continue;
		
		ll res = sum[m] - sum[pos-1] + (n-(m-pos+1)-1) * b[i] + a[i];
		if(i >= pos) res = res - a[i] + b[i];
		
		ans = max(ans, res);
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