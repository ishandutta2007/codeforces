#include <cstdio>
#include <cstring>

const int MV = 210;
int mem[MV*2][MV*2][4];
int X, Y, D, N, x[24], y[24];

int dp(int x, int y, int st)//st[0] = cur player
{
	if(x*x+y*y>=D*D)
		return 1;
	if(~mem[x+MV][y+MV][st])
		return mem[x+MV][y+MV][st];
	bool win=0;
	bool o = st>>1|(st&1)<<1;
	for(int i=0;i<N;++i)
		win |= !dp(x+::x[i], y+::y[i], o);
	if(o&2) win |= !dp(y, x, o^2);
	mem[x+MV][y+MV][st] = win;
	return win;
}

int main()
{
	scanf("%d%d%d%d", &X, &Y, &N, &D);
	for(int i=0;i<N;++i)
		scanf("%d%d", x+i, y+i);
	memset(mem, -1, sizeof mem);
	if(dp(X, Y, 3))
		printf("Anton\n");
	else
		printf("Dasha\n");
	return 0;
}