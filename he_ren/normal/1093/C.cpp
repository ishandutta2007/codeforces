#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

ll a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=(n>>1); ++i) scanf("%lld",&b[i]);
	
	a[1]=0; a[n]=b[1];
	for(int i=2; i<=(n>>1); ++i)
	{
		int j=n-i+1;
		if(b[i]-a[i-1] <= a[j+1])
			a[i]=a[i-1], a[j]=b[i]-a[i];
		else
			a[j]=a[j+1], a[i]=b[i]-a[j];
	}
	for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
	return 0;
}