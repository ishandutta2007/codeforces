#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll a,b,n;
	scanf("%lld%lld%lld",&a,&b,&n);
	
	int ans = 0;
	while(a<=n && b<=n)
	{
		++ans;
		if(a<b) a+=b;
		else b+=a;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}