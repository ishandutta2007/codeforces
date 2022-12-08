#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using ll = long long;

const int MN = 5e3 + 10;
const int MK = 5e3 + 10;

int N, K, p[MK*3];
ll ans, A, B;
bool n[MK], c[MK], all;

int main(void)
{
	scanf("%d%d", &N, &K);
	n[0] = 1;
	for(int i = 0, a, b;i < N;++i)
	{
		scanf("%d%d", &a, &b);
		A += a, B += b;
		if(all) continue;
		memcpy(c, n, sizeof n);
		memset(n, 0, sizeof n);
		//c -> n
		if(a+b >= K)
		{
			int y = std::max(0, a-K), x = std::min(a, a+b-K);//j-x ... j-y; inclusive-exclusive
			--y;
			assert(y < x);
			if(x-y>=K)
			{
				all = 1;
				continue;
			}
			else
			{
				memset(p, 0, sizeof p);
				for(int j = 0;j < K*3;)
					for(int k = 0;k < K;++k, ++j)
						p[j+1] = p[j] + c[k];

				y%=K, x%=K;
				if(x < y) x+=K;
				int *q = p+K*2;
				for(int j = 0;j < K;++j)
					n[j] = q[j-x]!=q[j-y];
			}
		}
		a %= K;
		for(int j = 0;j < K;++j)
			n[j] |= c[a>j?K+j-a:j-a];
		//for(int j = 0;j < K;++j) printf("[%d][%d]: %d\n", i, j, n[j]);
	}
	if(all) return printf("%lld\n", (A+B)/K), 0;
	for(int i = 0;i < K;++i)
		if(n[i])
		{
			//printf("can: %d\n", i);
			int u = (int)((A-i)%K);
			if(u) u = K-u;
			int v = (int)(B%K);
			ll ta = (A-i + (v<u?B-v-K+u:B-v+u))/K;
			if(ta>ans)ans=ta;
		}
	printf("%lld\n", ans);
	return 0;
}