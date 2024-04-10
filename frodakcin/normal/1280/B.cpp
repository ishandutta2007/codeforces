#include <cstdio>

char grid[70][70];
int r, c;
void ans(int v) {printf("%d\n", v);}
void solve(void)
{
	scanf("%d%d", &r, &c);
	for(int i = 0;i < r;++i)
		scanf(" %s", grid[i]);

	bool can = 0;
	for(int i = 0;i < r;++i)
	{
		for(int j = 0;j < c;++j)
			if(grid[i][j] == 'A')
			{
				can = 1;
				break;
			}
		if(can) break;
	}
	if(!can)
		return (void) printf("MORTAL\n");

	bool im_bad = 1;
	//0
	for(int i = 0;i < r;++i)
		for(int j = 0;j < c;++j)
			if(grid[i][j] == 'P')
				im_bad = 0;
	if(im_bad) return ans(0);

	//1
	for(int i = 0;i <= r;++i)
		if(i == r) return ans(1);
		else if(grid[i][0] == 'P')
			break;
	for(int i = 0;i <= r;++i)
		if(i == r) return ans(1);
		else if(grid[i][c-1] == 'P')
			break;
	for(int i = 0;i <= c;++i)
		if(i == c)return ans(1);
		else if(grid[0][i] == 'P')
				break;
	for(int i = 0;i <= c;++i)
		if(i == c)return ans(1);
		else if(grid[r-1][i] == 'P')
				break;
	//2
	if(grid[0][0] == 'A' || grid[r-1][0] == 'A' || grid[r-1][c-1] == 'A' || grid[0][c-1] == 'A')
		return ans(2);
	for(int i = 0;i < r;++i)
		for(int j = 0;j <= c;++j)
			if(j == c) return ans(2);
			else if(grid[i][j] == 'P')
				break;
	for(int i = 0;i < c;++i)
		for(int j = 0;j <= r;++j)
			if(j == r) return ans(2);
			else if(grid[j][i] == 'P')
				break;
	
	//3
	for(int i = 0;i < r;++i)
		if(grid[i][0] == 'A' || grid[i][c-1] == 'A')
			return ans(3);
	for(int i = 0;i < c;++i)
		if(grid[0][i] == 'A' || grid[r-1][i] == 'A')
			return ans(3);

	return ans(4);
}

int t;
int main(void)
{
	scanf("%d", &t);
	for(int i = 0;i < t;++i)
		solve();
	return 0;
}