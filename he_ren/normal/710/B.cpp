#include<cstdio>
#include<algorithm>
const int MAXN = 3e5 + 5;
using namespace std;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	printf("%d",a[(n+1)>>1]);
	return 0;
}