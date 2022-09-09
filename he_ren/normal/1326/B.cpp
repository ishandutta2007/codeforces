#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	int mx=0;
	for(int i=1; i<=n; ++i)
	{
		a[i] = b[i] + mx;
		if(mx<a[i]) mx=a[i];
		printf("%d ",a[i]);
	}
	return 0;
}