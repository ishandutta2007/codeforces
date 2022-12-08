#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
#include <cassert>

using ll = long long;
const int V = 1e6 + 100, P = 80000;
int N, K;

bool c[V];
int p[P], t[V], l[V];

void pcp(void)
{
	for(int i = 2;i < V;i++)
	{
		if(!c[i])
			t[i] = i-1, p[l[i] = ++*p] = i;
		for(int j = 1, k;j <= *p && (k = p[j]*i) < V;j++)
		{
			assert(!c[k]);
			c[k] = 1;
			l[k] = l[i];
			if(i%p[j]) t[k] = t[i]*(p[j]-1);
			else
			{
				t[k] = t[i]*p[j];
				break;
			}
		}
	}
}

ll f;
int main(void)
{
	pcp();
	f = 1LL;
	scanf("%d%d", &N, &K);
	if(K == 1)
		return printf("3\n"), 0;//i think this works for K >= 2??
	std::nth_element(t+2, t+(K+2), t+N+1);
	for(int i = 0;i <= K;i++)
		f += t[i+2];
	printf("%lld\n", f);
	return 0;
}