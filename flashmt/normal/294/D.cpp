#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const string direction[] = {"UR", "DR", "DL", "UL"};
const int dx[] = {-1, 1, 1, -1};
const int dy[] = {1, 1, -1, -1};
const int DELTA = 200020;

int m, n, sx, sy, sz, row[500500], col[500500], flagRow[500500], flagCol[500500];
set <long long> s;
string dir;

void add(int f[], int x)
{
	for (int i = x; i < 500000; i += i & -i) f[i]++;
}

int get(int f[], int x)
{
	int res = 0;
	for (int i = x; i; i -= i & -i) res += f[i];
	return res;
}

long long encode(int x, int y, int z)
{
	return (1000000LL * x + y) * 4 + z;
}

int repeat(int x, int y, int z, int xx, int yy)
{
	if (x > xx) swap(x, xx), swap(y, yy);

	if (z % 2 == 0) 
	{
		int idRow = x + y, idCol1 = yy - xx + DELTA, idCol2 = y - x + DELTA;
		if (flagRow[idRow]) return abs(xx - x) + 1;
		flagRow[idRow] = 1;
		add(row, idRow);
		return get(col, idCol2) - get(col, idCol1 - 1);
	}
	
	int idCol = y - x + DELTA, idRow1 = x + y, idRow2 = xx + yy;
	if (flagCol[idCol]) return abs(x - xx) + 1;
	flagCol[idCol] = 1;
	add(col, idCol);
	return get(row, idRow2) - get(row, idRow1 - 1);
}

int main()
{
	//freopen("d.in", "r", stdin);
	cin >> m >> n >> sx >> sy >> dir;
	for (sz = 0; sz < 4; sz++)
		if (direction[sz] == dir) break;
		
	int x = sx, y = sy, z = sz;
	
	if (!sz)
	{
		if (x == 1 && y == n) z = 2;
		else
			if (x == 1) z = 1;
			else 
				if (y == n) z = 3;
	}
	
	if (sz == 1)
	{
		if (x == m && y == n) z = 3;
		else
			if (x == m) z = 0;
			else 
				if (y == n) z = 2;
	}
	
	if (sz == 2)
	{
		if (x == m && y == 1) z = 0;
		else
			if (x == m) z = 3;
			else 
				if (y == 1) z = 1;
	}
	
	if (sz == 3)
	{
		if (x == 1 && y == 1) z = 1;
		else
			if (x == 1) z = 2;
			else 
				if (y == 1) z = 0;
	}
	
	long long ans = 1, covered = 0;
	
	while (1)
	{
		if (s.count(encode(x, y, z))) break;
		s.insert(encode(x, y, z));

		int kx, ky;
		if (dx[z] > 0) kx = m - x;
		else kx = x - 1;
		if (dy[z] > 0) ky = n - y;
		else ky = y - 1;
		
		int step = min(ky, kx), xx, yy, zz;
		xx = x + dx[z] * step;
		yy = y + dy[z] * step;
		
		if (ky == kx) zz = (z + 2) % 4;
		else
		{
			if (!z) zz = (xx == 1 ? 1 : 3);
			if (z == 1) zz = (xx == m ? 0 : 2);
			if (z == 2) zz = (xx == m ? 3 : 1);
			if (z == 3) zz = (xx == 1 ? 2 : 0);
		}
		
		covered += step + 1 - repeat(x, y, z, xx, yy);
		ans += step;
		if (covered == 1LL * m * n / 2) 
		{
			cout << ans << endl;
			return 0;
		}
		x = xx; y = yy; z = zz;
	}
	
	cout << -1 << endl;
}