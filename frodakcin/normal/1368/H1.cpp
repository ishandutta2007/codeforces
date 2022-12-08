#include <cstdio>
#include <algorithm>

const int MN = 1e5+10;

int N, M;
char b[MN], t[MN], l[MN], r[MN];
int dpr[MN][2], dpc[MN][2];
int main(void)
{
	scanf("%d%d%*d", &N, &M);
	scanf(" %s %s %s %s", l, r, t, b);
	for(int i=0;i<M;++i)
		dpr[0][t[i]=='R']++;
	//printf("%d %d\n", dpr[0][0], dpr[0][1]);

	for(int i=0;i<N;++i)
	{
		dpr[i][l[i]=='R']++;
		dpr[i][r[i]=='R']++;
		if(i+1<N)
		{
			dpr[i+1][0]=std::min(dpr[i][0], dpr[i][1]+M);
			dpr[i+1][1]=std::min(dpr[i][1], dpr[i][0]+M);
		}
	}
	for(int i=0;i<M;++i)
		dpr[N-1][b[i]=='R']++;
	//printf("%d\n", std::min({dpr[N-1][0], dpr[N-1][1]}));

	for(int i=0;i<N;++i)
		dpc[0][l[i]=='R']++;
	for(int i=0;i<M;++i)
	{
		dpc[i][t[i]=='R']++;
		dpc[i][b[i]=='R']++;
		if(i+1<M)
		{
			dpc[i+1][0]=std::min(dpc[i][0], dpc[i][1]+N);
			dpc[i+1][1]=std::min(dpc[i][1], dpc[i][0]+N);
		}
	}
	for(int i=0;i<N;++i)
		dpc[M-1][r[i]=='R']++;

	printf("%d\n", std::min({dpr[N-1][0], dpr[N-1][1], dpc[M-1][0], dpc[M-1][1]}));
	return 0;
}