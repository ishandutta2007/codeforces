#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a<=b)
	{
		printf("%d\n",b);
		return;
	}
	a-=b;
	
	if(d>=c){ printf("-1\n"); return;}
	
	printf("%lld\n",b + (ll)((a+c-d-1)/(c-d)) * c);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}