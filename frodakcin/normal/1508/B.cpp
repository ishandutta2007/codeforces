#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using ll = long long;

const ll INF = 2e18;

ll p2(int v) {return v>=61?INF:1ll<<v;}

void solve()
{
	int N;
	ll K;
	scanf("%d%lld", &N, &K); --K;
	if(N<=62 && (1ll<<N-1) <= K)
		return (void) printf("-1\n");

	for(int i=0,j;i<N;i=j)
	{
		for(j=i+1;j<N;++j)
			if(K>=p2(N-j-1))
				K-=p2(N-j-1);
			else
				break;
		for(int k=i;k<j;++k)
			printf("%d ", j-(k-i));
	}
	assert(K==0);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;++i) solve();
	return 0;
}