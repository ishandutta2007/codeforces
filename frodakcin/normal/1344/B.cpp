#include <cstdio>

const int MN = 1e3 + 10;
int N, M, ec, er, ans, dx[]={1,0,0,-1}, dy[]={0,1,-1,0};
bool a[MN][MN], v[MN][MN];
char s[MN];

void dfs(int x, int y)
{
	v[x][y] = 1;
	for(int i=0, nx, ny;i<4;++i)
	{
		nx = x+dx[i], ny=y+dy[i];
		if(0 <= nx&&nx < N && 0<=ny&&ny<M && !v[nx][ny] && a[nx][ny])
			dfs(nx, ny);
	}
}
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
	{
		scanf(" %s", s);
		for(int j=0;j<M;++j)
			a[i][j] = s[j] == '#';//black
	}
	for(int i=0;i<N;++i)
	{
		int g=a[i][0];
		for(int j=1;j<M;++j)
			if(a[i][j] != a[i][j-1])
				++g;
		//printf("GC: %d\n", g);
		if(g>2)
			return printf("-1\n"), 0;
		if(g == 0)
			++ec;
	}
	for(int i=0;i<M;++i)
	{
		int g=a[0][i];
		for(int j=1;j<N;++j)
			if(a[j][i] != a[j-1][i])
				++g;
		//printf("GR: %d\n", g);
		if(g>2)
			return printf("-1\n"), 0;
		if(g==0)
			++er;
	}
	if((ec>0) ^ (er>0))
		return printf("-1\n"), 0;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(a[i][j] && !v[i][j])
				dfs(i, j), ++ans;
	printf("%d\n", ans);
	return 0;
}