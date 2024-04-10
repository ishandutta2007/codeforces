#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

ll a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	if(n==1)
	{
		printf("1 1\n");
		printf("%lld\n",-a[1]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
	
	printf("%d %d\n",1,n-1);
	for(int i=1; i<n; ++i)
	{
		ll b = a[i] * (n-1);
		printf("%lld ",b);
		a[i] += b;
	}
	putchar('\n');
	
	printf("%d %d\n",2,n);
	for(int i=2; i<n; ++i) printf("0 ");
	printf("%lld\n",a[n] * (n-1));
	a[n] *= n;
	
	printf("%d %d\n",1,n);
	for(int i=1; i<=n; ++i)
		printf("%lld ",-a[i]);
	return 0;
}