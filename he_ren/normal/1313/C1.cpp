#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

int n,lim[MAXN];
int a[MAXN],b[MAXN];

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&lim[i]);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		a[i]=lim[i];
		for(int j=i-1; j>=1; --j)
			a[j] = min(a[j+1], lim[j]);
		for(int j=i+1; j<=n; ++j)
			a[j] = min(a[j-1], lim[j]);
		
		ll tmp=0;
		for(int j=1; j<=n; ++j)
			tmp+=a[j];
		if(ans<tmp)
		{
			ans=tmp;
			for(int j=1; j<=n; ++j) b[j]=a[j];
		}
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",b[i]);
	return 0;
}