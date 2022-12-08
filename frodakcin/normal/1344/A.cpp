#include <cstdio>
#include <cstring>

using ll = long long;
const ll INF = 1e9 + 10;
const int MN = 2e5 + 10;
int N, T, a[MN];
bool works, u[MN];

int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i=0;i<N;++i)
			scanf("%d", a+i);
		works = 1;
		for(int i=0;i<N;++i)
		{
			int to =(int)((i+a[i]+INF*N)%N);
			if(u[to]) works = 0;
			else u[to] = 1;
		}
		if(works) printf("YES\n");
		else printf("NO\n");
		memset(u, 0, N*sizeof(u[0]));
	}
	return 0;
}