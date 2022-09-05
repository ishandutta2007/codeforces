//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
typedef vector<vector<char> > grids;
typedef vector<vector<int> > gridsI;
int n, m;
void initI(gridsI &s)
{
	s = vector<vector<int> >(n+1, vector<int>(m+1, 0));
}
void init(grids &g, gridsI &s)
{
	initI(s);
	assert(g.size()==n+1&&g[0].size()==m+1);
	assert(s.size()==n+1&&s[0].size()==m+1);
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			s[i][j] = g[i][j]=='X';
		}
	}
	for (int i=0; i<=n; i++) for (int j=1; j<=m; j++) s[i][j] += s[i][j-1];
	for (int i=1; i<=n; i++) for (int j=0; j<=m; j++) s[i][j] += s[i-1][j];
}
int query(gridsI &s, int xl, int yl, int xr, int yr)
{
	xl = max(xl, 1);
	yl = max(yl, 1);
	xr = min(xr, n);
	yr = min(yr, m);
	assert(xl<=n&&yl<=m&&xr>=0&&yr>=0);
	return s[xr][yr]-s[xl-1][yr]-s[xr][yl-1]+s[xl-1][yl-1];
}
int querySqr(gridsI &s, int x, int y, int r)
{
	return query(s, x-r, y-r, x+r, y+r);
}
grids G, g;
char _s[1000111];
gridsI sumG, sumg;

bool check(int r)
{
	g = vector<vector<char> > (n+1, vector<char>(m+1, '.'));
	for (int i=r+1; i<=n-r; i++)
	{
		for (int j=r+1; j<=m-r; j++)
		{
			if (querySqr(sumG, i, j, r)==(2*r+1)*(2*r+1))
			{
				g[i][j]='X';
			}
		}
	}
	init(g, sumg);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if ((querySqr(sumg, i, j, r)>0)!=(G[i][j]=='X')) return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	G.PB(vector<char>(m+1, '.'));
	for (int i=1; i<=n; i++)
	{
		scanf("%s", _s+1);
		static vector<char> tmp;
		tmp.clear();
		for (int j=0; j<=m; j++) tmp.PB(_s[j]);
		G.PB(tmp);
	}
	
	init(G, sumG);
	int l = 0, r = min(n, m);
	while (l<=r)
	{
		int mid = l+r>>1;
		if (check(mid)) l = mid+1;
		else r = mid-1;
	}
	check(r);
	printf("%d\n", r);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) putchar(g[i][j]);
		puts("");
	}
	return 0;
}