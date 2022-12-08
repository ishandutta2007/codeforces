#include <cstdio>

using ll = long long;
const int MN = 2e5+10;

int N, c[25], a[MN];
ll f;

int main()
{
	scanf("%d", &N);
	for(int i=0,x;i<N;++i)
	{
		scanf("%d", &x);
		for(int j=0;j<20;++j)
			if(x>>j&1)
				++c[j];
	}
	for(int i=0;i<20;++i)
		for(int j=0;j<c[i];++j)
			a[j]|=1<<i;
	for(int i=0;i<N;++i)
		f+=(ll)a[i]*a[i];
	printf("%lld\n", f);
	return 0;
}