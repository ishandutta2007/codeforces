#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	ll ans = 0;
	for(int i=2; i+1<=n; ++i)
		ans += i * (i+1);
	printf("%lld",ans);
	return 0;
}