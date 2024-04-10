#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define maxn 305
using namespace std;
int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
int nx[8][2];
int nxs[8];
short dp[8][31][maxn][maxn];
bool bdp[8][31][maxn][maxn];
bool ju(int x)
{
	if(x <= 0) return false;
	if(x >= maxn) return false;
	return true;
}
bool est[8][31][maxn][maxn];
bool best[8][31][maxn][maxn];
int n, t[35];
bool gest(int a, int b, int c, int d)
{
	if(best[a][b][c][d])
		return est[a][b][c][d];
	best[a][b][c][d] = true;
	if(c == maxn / 2 && d == maxn / 2 && a == 0 && b == 0)
		return est[a][b][c][d] = true;
	est[a][b][c][d] = false;
	if(!b) 
		return false;
	for(int i = 0; i < 2; i++)
	{
		int nows = nx[a][i];
		int edx = c - t[b - 1] * move[nows][0], 
			edy = d - t[b - 1] * move[nows][1];
		if(b) 
			if(ju(edx) && ju(edy))
				if(gest(nows, b - 1, edx, edy) )
					return est[a][b][c][d] = true; 
	}	
	return est[a][b][c][d] = false;
} 
short max(short a, short b)
{
	if(a < b) return b;
	return a;
}

short gdp(int a, int b, int c, int d)
{
	if(bdp[a][b][c][d]) return dp[a][b][c][d];
	bdp[a][b][c][d] = true;
	if(a == 0 && c == maxn / 2 && d == maxn / 2)
	{
		if(b == 0) return dp[a][b][c][d] = t[0];
		else return dp[a][b][c][d] = 0;
	}
	
	dp[a][b][c][d] = 0;
	for(int i = 0; i < 2; i++)
		if(b)
		{
			int edx = c - t[b - 1] * move[nx[a][i]][0],
			edy = d - t[b - 1] * move[nx[a][i]][1];
			if(ju(edx) && ju(edy)) 
				if(gest(nx[a][i], b - 1, edx, edy))
					dp[a][b][c][d] = t[b] + 1;//important
		}
		int nows = a;
		int edx = c - move[nows][0], edy = d - move[nows][1];
		if(ju(edx) && ju(edy))
			dp[a][b][c][d] = max(dp[a][b][c][d], gdp(nows, b, edx, edy) - 1);		
			
	return dp[a][b][c][d];
}

int main()
{
	memset(nxs, 0, sizeof(nxs));
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			if(i >= 4 && j >= 4) continue;
			if(i < 4 && j < 4) continue;
			if(move[i][0] == move[j][0] || move[i][1] == move[j][1])
				nx[i][nxs[i]++] = j;
		}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	if(n == 1)
	{
		printf("%d\n", t[0]);
		return 0;
	}
	t[0]--;
	int ans = 0;
	for(int i = maxn / 2; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
		{
			bool flag = false;
			for(int k = 0; k < n; k++)
				for(int l = 0; l < 8; l++)
				{
					if(flag) 
						break;
					if(gdp(l, k, i, j))
					{
						flag = true;
						break;
					}
				}
			if(flag) 
				ans++;
			if(flag && i != maxn / 2)
				ans++;
		}
	printf("%d\n", ans);
	return 0;
}