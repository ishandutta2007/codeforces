#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll blk=0, wht=0;
	for(int i=1; i<=n; ++i)
	{
		blk += a[i]>>1;
		wht += a[i]>>1;
		if(a[i]&1)
			++(i&1? blk: wht);
	}
	printf("%lld",min(blk,wht));
	return 0;
}