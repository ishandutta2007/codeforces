#include <cstdio>
#include <bitset>
#include <algorithm>

using ll = long long;

const int MAX = 5003000;

ll f;
int B, C;

std::bitset<2*MAX> a;

int main()
{
	scanf("%d%d", &B, &C);
	for(int i=1;i<=B;++i)
	{
		ll x=(ll)i*i;
		int v=0;
		for(int j=i-1;j>=0;--j)
		{
			ll y=(ll)j*j;
			if(x-y>C) break;
			a[MAX-i-j]=1;
			a[MAX-i+j]=1;
			++v;
		}
		f += std::min<ll>(C, x)-v;
	}
	//printf("%lld\n", f);
	f*=2;
	f += a.count();
	printf("%lld\n", f);
	return 0;
}