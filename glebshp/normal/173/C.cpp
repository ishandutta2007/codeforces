#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000;
const int inf = 1000 * 1000 * 1000;

int n, m;
int field[size][size];
int vsum[size][size];
int hsum[size][size];
int ansval;

inline int getvsum(int ver, int lb, int rb)
{
	if (lb > rb)
		swap(lb, rb);
	return vsum[ver][rb + 1] - vsum[ver][lb];
}

inline int gethsum(int hor, int lb, int rb)
{
	if (lb > rb)
		swap(lb, rb);
	return hsum[hor][rb + 1] - hsum[hor][lb];
}

void modulate3(int x, int y)
{
	int psum = 0;
	if (x - 2 < 0 || y + 2 >= m)
		return;
	psum = gethsum(x, y, y + 2) + field[x - 1][y + 2] + gethsum(x - 2, y, y + 2);
	x -= 2;
	int sz = 2;
	ansval = max(ansval, psum);
	while (x - 2 >= 0 && y - 2 >= 0 && x + sz + 2 < n && y + sz + 2 < m)
	{
		psum += field[x][y - 1] + getvsum(y - 2, x, x + sz + 2) + gethsum(x + sz + 2, y - 1, y + sz + 2) + getvsum(y + sz + 2, x + sz + 1, x - 2) + gethsum(x - 2, y + sz + 1, y - 2);
		ansval = max(ansval, psum);
		x -= 2;
		y -= 2;
		sz += 4;
	}
}

void modulate5(int x, int y)
{
	int psum = 0;
	if (x - 2 < 0 || y + 2 >= m)
		return;
	psum = field[x][y];
	int sz = 0;
	while (x - 2 >= 0 && y - 2 >= 0 && x + sz + 2 < n && y + sz + 2 < m)
	{
		psum += field[x][y - 1] + getvsum(y - 2, x, x + sz + 2) + gethsum(x + sz + 2, y - 1, y + sz + 2) + getvsum(y + sz + 2, x + sz + 1, x - 2) + gethsum(x - 2, y + sz + 1, y - 2);
		ansval = max(ansval, psum);
		x -= 2;
		y -= 2;
		sz += 4;
	}

}

void modulate(int x, int y)
{
	modulate3(x, y);
	modulate5(x, y);
}

void calc_psums()
{
	for (int i = 0; i < n; i++)
	{
		hsum[i][0] = 0;
		for (int j = 1; j <= m; j++)
			hsum[i][j] = hsum[i][j - 1] + field[i][j - 1];
	}
	for (int i = 0; i < m; i++)
	{
		vsum[i][0] = 0;
		for (int j = 1; j <= n; j++)
			vsum[i][j] = vsum[i][j - 1] + field[j - 1][i];
	}
}

int main() {
	//freopen("problemC.in", "r", stdin);
	//freopen("problemC.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &field[i][j]);

	ansval = -inf;
	calc_psums();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			modulate(i, j);

	cout << ansval << endl;

	return 0;
}