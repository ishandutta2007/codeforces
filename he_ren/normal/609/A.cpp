#include<cstdio>
#include<algorithm>
const int MAXN = 100 + 5;
using namespace std;

int a[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1; i<=n; ++i)
	{
		sum+=a[n-i+1];
		if(sum>=m)
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}