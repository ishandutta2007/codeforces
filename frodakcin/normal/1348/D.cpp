#include <cstdio>
#include <cassert>
#include <algorithm>

const int MN = 1e9;
using ll = long long;
int T, A;
ll N, cum, d;

bool tryd(int D)
{
	cum = D, d = 1;
	for(int i = 0;i < D;++i)
	{
		int k = std::min(d, (N-cum)/(D-i));
		d += k, cum += (D-i)*k;
	}
	if(cum == N)
	{
		cum = D, d = 1;
		printf("%d\n", D);
		for(int i = 0;i < D;++i)
		{
			int k = std::min(d, (N-cum)/(D-i));
			d += k, cum += (D-i)*k;
			printf("%d ", k);
		}
		printf("\n");
		return 1;
	}
	return 0;
}
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &N);
		--N;
		A = 0;
		for(int i = 0;;++i)
		{
			assert(i <= 40);
			if(tryd(i))
				break;
		}
	}
	return 0;
}