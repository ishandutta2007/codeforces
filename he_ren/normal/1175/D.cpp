#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];
ll suf[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=n; i>=1; --i) suf[i] = suf[i+1] + a[i];
	
	reverse(suf+1,suf+n+1);
	sort(suf+1,suf+n);
	reverse(suf+1,suf+n);
	
	ll ans = suf[n];
	for(int i=1; i<d; ++i)
		ans += suf[i];
	printf("%lld",ans);
	return 0;
}