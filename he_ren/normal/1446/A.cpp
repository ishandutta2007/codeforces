#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

pii a[MAXN];

void solve(void)
{
	int n;
	ll lim;
	scanf("%d%lld",&n,&lim);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].first), a[i].second = i;
	
	sort(a+1,a+n+1);
	while(n && a[n].first > lim) --n;
	if(!n){ printf("-1\n"); return;}
	
	ll need = (lim+1) / 2;
	if(a[n].first >= need){ printf("1\n%d\n",a[n].second); return;}
	
	ll sum = 0;
	int cur = 0;
	while(cur <= n && sum < need)
		sum += a[++cur].first;
	if(cur > n){ printf("-1\n"); return;}
	if(sum > lim) --cur;
	
	printf("%d\n",cur);
	for(int i=1; i<=cur; ++i)
		printf("%d ",a[i].second);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}