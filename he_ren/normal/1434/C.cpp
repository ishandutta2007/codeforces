#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	
	if(d > c)
	{
		if(b * c < a) printf("-1\n");
		else printf("%lld\n",a);
		return;
	}
	
	ll lst = c/d;
	if(lst * d * b - a >= 0)
	{
		ll x = (a + d * b - 1) / (d * b) - 1;
		
		ll res = x * (x+1) / 2 * d * b - (x + 1) * a;
		printf("%lld\n",-res);
		return;
	}
	
	ll already = lst * (lst+1) / 2 * d * b - (lst + 1) * a;
	already = -already;
	
	if(c%d * b + c/d * d * b - a >= 0) printf("%lld\n",already);
	else printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}