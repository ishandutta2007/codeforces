#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n,m,x,d,y;
int a[MAXN], b[MAXN];

int p[MAXN];

ll calc(int l,int r)
{
	if(l>r) return 0;
	
	int mx = 0;
	for(int i=l; i<=r; ++i) mx = max(mx, a[i]);
	
	int len = r-l+1;
	if(len < d)
	{
		if(mx > a[l-1] && mx > a[r+1]) printf("-1"), exit(0);
		else return (ll)y * len;
	}
	
	ll res = linf;
	res = (ll)y * (len%d) + (ll)x * (len/d);
	if(mx < a[l-1] || mx < a[r+1])
		res = min(res, (ll)y * len);
	else res = min(res, x + (ll)y * (len-d));
	
	return res;
}

int main(void)
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&d,&y);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	static int pos[MAXN];
	for(int i=1; i<=n; ++i)
		pos[a[i]] = i;
	 
	for(int i=1; i<=m; ++i)
		p[i] = pos[b[i]];
	p[0] = 0; p[m+1] = n+1;
	
	for(int i=1; i<=m; ++i)
		if(p[i] < p[i-1]) return printf("-1"), 0;
	
	ll ans = 0;
	for(int i=1; i<=m+1; ++i)
		ans += calc(p[i-1]+1, p[i]-1);
	
	printf("%lld",ans);
	return 0;
}