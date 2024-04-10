#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

int n,m,q,N,M;
int a[MAXN][MAXN];
int sum[2][MAXN][MAXN];

string s;

ll solve(int la,int ra,int lb,int rb,int xa,int xb,int ya,int yb,bool rev)
{
	if (ra < xa || xb < la || rb < ya || yb < lb)
		return 0;
	xa = max(xa,la);
	xb = min(xb,ra);
	ya = max(ya,lb);
	yb = min(yb,rb);
	if (ra - la + 1 == n && rb - lb + 1 == m)
	{
		xa = xa - la + 1;
		xb = xb - la + 1;
		ya = ya - lb + 1;
		yb = yb - lb + 1;
		return sum[rev][xb][yb] - sum[rev][xb][ya - 1] - sum[rev][xa - 1][yb] + sum[rev][xa - 1][ya - 1];
	}
	if ((la == xa && xb == ra) || (lb == ya && yb == rb))
		return (ll)(xb - xa + 1) * (yb - ya + 1) / 2;
	int mida = la + ((ra - la) >> 1),midb = lb + ((rb - lb) >> 1);
	if ((ra - la + 1) / n > (rb - lb + 1) / m)
		return solve(la,mida,lb,rb,xa,xb,ya,yb,rev) + solve(mida + 1,ra,lb,rb,xa,xb,ya,yb,rev ^ 1);
	if ((ra - la + 1) / n < (rb - lb + 1) / m)
		return solve(la,ra,lb,midb,xa,xb,ya,yb,rev) + solve(la,ra,midb + 1,rb,xa,xb,ya,yb,rev ^ 1);
	return solve(la,mida,lb,midb,xa,xb,ya,yb,rev) + solve(la,mida,midb + 1,rb,xa,xb,ya,yb,rev ^ 1) + solve(mida + 1,ra,lb,midb,xa,xb,ya,yb,rev ^ 1) + solve(mida + 1,ra,midb + 1,rb,xa,xb,ya,yb,rev);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> q;
	N = n;
	while (N < 1e9)
		N <<= 1;
	M = m;
	while (M < 1e9)
		M <<= 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 1;j <= m;j++)
			a[i][j] = s[j - 1] - '0';
	}
	for (int op = 0;op <= 1;op++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				sum[op][i][j] = sum[op][i - 1][j] + sum[op][i][j - 1] - sum[op][i - 1][j - 1] + (a[i][j] ^ op);
	while (q--)
	{
		int xa,ya,xb,yb;
		cin >> xa >> ya >> xb >> yb;
		cout << solve(1,N,1,M,xa,xb,ya,yb,0) << endl;
	}
	return 0;
}