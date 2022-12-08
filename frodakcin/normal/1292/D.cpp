#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MN = 1e6 + 100;
const int MK = 5e3 + 100;
const int MP = 700;
int N, k[MN];

int p[MP], P;
bool comp[MK];
int price[MK];
int vp[MP][MK];
void sieve()
{
	for(int i = 2;i < MK;++i)
	{
		if(!comp[i])
		{
			p[P++] = i;
			price[i] = 1;
		}
		for(int j = 0, k;j < P && (k = p[j]*i) < MK;++j)
		{
			assert(!comp[k]);
			comp[k] = 1;
			price[k] = price[i] + 1;
			if(i%p[j] == 0) break;
		}
	}
}

int wh[MK];//first occurrence of k-value or N if not in set
ll ans;
int L, R;
int main(void)
{
	sieve();
	for(int i = 2;i < MK;++i)
		price[i] += price[i-1];
	for(int i = 0;i < P;++i)
		for(int j = p[i];j < MK;j *= p[i])
			for(int k = j;k < MK;k += j)
				vp[i][k]++;

	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", k+i), ans += price[k[i]];
	//printf("PREANS %d\n", ans);
	std::sort(k, k+N);
	for(int i = 0, j = 0;i < MK;++i)
	{
		wh[i] = j;
		for(;j < N && k[j] == i;++j);
	}
	L = 0, R = N;
	for(int i = P-1, j;i >= 0;--i)
	{
		int R1 = R;
		for(j = p[i];j < MK;j += p[i])
		{
			int L1 = wh[j];
			if(L>L1) L1=L;
			if(R-L1 > N/2)
			{
				ans += vp[i][j]*(N-2*(R-L1));
				L = L1;
			}
			else
				break;
		}
		R = std::min(R, j<MK?wh[j]:N);
	}
	printf("%lld\n", ans);
	return 0;
}