#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	ll ans=0;
	
	ll tmp = m/(d+1);
	ans += tmp*d*a[1];
	ans += tmp*a[2];
	m%=(d+1);
	ans += (ll)m*a[1];
	
	printf("%lld",ans);
	return 0;
}