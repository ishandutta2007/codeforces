#include<cstdio>
#include<algorithm>
const int MAXN = 1e3 + 5;
using namespace std;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1, j=n; i<=j; ++i,--j)
		if(i==j) printf("%d ",a[i]);
		else printf("%d %d ",a[i],a[j]);
	return 0;
}