#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
int my, mx, k;
char t [N][N];
char vis [N][N];
vector <char> signs;
int j;
vector <char> pff;

void dfs (int y, int x)
	{
	if (vis[y][x]!=0)
		return;
	
	vis[y][x] = pff[j];

	if (t[y][x]=='R')
		j++;
	
	dfs(y, x+1);
	dfs(y, x-1);
	dfs(y+1, x);
	dfs(y-1, x);
	}

void solve ()
	{
	int y, x;
	scanf ("%d%d%d", &my, &mx, &k);
	
	for (y=1; y<=my; y++)
		scanf ("%s", t[y]+1);

	for (y=0; y<=my+1; y++)
		for (x=0; x<=mx+1; x++)
			vis[y][x] = '$';

	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			vis[y][x] = 0;
	
	int R = 0;
	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			if (t[y][x]=='R')
				R++;

	pff.clear();
	for (int i=0; i<k; i++)
		{
		int r = R/k;
		if (i<R%k)
			r++;
		while (r--)
			pff.push_back(signs[i]);
		}

	pff.push_back(pff.back());

	j = 0;
	dfs(1, 1);
	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			printf ("%c",vis[y][x]);
		printf ("\n");
		}
	}	

int main ()
	{
	for (char c='a'; c<='z'; c++) signs.push_back(c);
	for (char c='A'; c<='Z'; c++) signs.push_back(c);
	for (char c='0'; c<='9'; c++) signs.push_back(c);
	
	int q;
	scanf ("%d",&q);
	while (q--)
		solve();
	
	return 0;
	}