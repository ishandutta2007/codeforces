#include <cstdio>
#include <algorithm>

template<class T> bool ckmin(T* a, T b){return b<*a?*a=b,1:0;}
const int MN = 2e5 + 10;
using ll = long long;
int a[MN], N, K;
ll t, ans=1e18, p[MN];

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
		scanf("%d",a+i);
	std::sort(a,a+N);
	for(int i=0,j;i<N;i=j)
	{
		for(j=i+1;a[i]==a[j];++j);
		if(j-i>=K)
			return printf("0\n"), 0;
	}
	for(int i=0;i<N;++i)
		p[i+1]=p[i]+a[i];
	for(int i=0;i<N;++i)
	{
		if(i+1>=K)
			ckmin(&ans, (ll)i*a[i]-p[i]-(i+1-K));
		if(i+K<=N)
			ckmin(&ans, p[N]-p[i]-(ll)(N-i)*a[i]-(N-i-K));
		ckmin(&ans, (p[N]-p[i]-(ll)(N-i)*a[i])+((ll)i*a[i]-p[i])-(N-K));
	}
	printf("%lld\n", ans);
}