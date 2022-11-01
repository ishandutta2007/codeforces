#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;

int n, q;

bool stanje[2][maxn];

int br, brd1, brd2;

void ubaci(int x, int y)
{
	if(x == 0)
	{
		if(y > 0 && stanje[1][y - 1])
		{
			if(stanje[x][y]) brd1--;
			else brd1++;
		}
		if(y < n - 1 && stanje[1][y + 1])
		{
			if(stanje[x][y]) brd2--;
			else brd2++;
		}
		if(stanje[1][y])
		{
			if(stanje[x][y]) br--;
			else br++;
		}
	}
	else
	{
		if(y > 0 && stanje[0][y - 1])
		{
			if(stanje[x][y]) brd1--;
			else brd1++;
		}
		if(y < n - 1 && stanje[0][y + 1])
		{
			if(stanje[x][y]) brd2--;
			else brd2++;
		}
		if(stanje[0][y])
		{
			if(stanje[x][y]) br--;
			else br++;
		}
	}
	stanje[x][y] = !stanje[x][y];
	return;
}

int main()
{
	cin >> n >> q;
	int r, c;
	REP(i, 0, q)
	{
		scanf("%d%d", &r, &c);
		r--; c--;
		ubaci(r, c);
		if(br + brd1 + brd2 != 0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}