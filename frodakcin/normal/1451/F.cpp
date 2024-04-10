#include <cstdio>
#include <cstring>

const int MN = 1e2+10;

int T, N, M, a, v[MN*2];

void solve()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			scanf("%d", &a);
			v[i+j]^=a;
		}
	bool ok=0;
	for(int i=0;i<N+M-1;++i)
		if(v[i])
			ok=1;
	if(ok) printf("Ashish\n");
	else printf("Jeel\n");
	memset(v, 0, (N+M-1)*sizeof*v);
}

int main()
{
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}