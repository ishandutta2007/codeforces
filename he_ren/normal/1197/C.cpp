#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];
int b[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<n; ++i)
		b[i] = a[i] - a[i+1];
	
	sort(b+1,b+n);
	ll ans = a[n] - a[1];
	for(int i=1; i<d; ++i)
		ans += b[i];
	printf("%lld\n",ans);
	return 0;
}