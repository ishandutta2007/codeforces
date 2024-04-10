#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433832795

const int size = 6;

int n, m;
int freecells[1 << (size * 2)], ans[50][1 << (size * 2)], pr[50];
bool match[1 << (size * 2)][1 << (size * 2)]; 

int calc_cells(int p)
{
	int i, a = 0;
	for (i = 0; i < m; i++)
	{
		if (p % 4 != 0)
			a++;
		p /= 4;
	}
	return a;
}

bool couldbe(int p)
{
	int i;
	for (i = 0; i < m; i++)
	{
		pr[i] = p % 4;
		p /= 4;
	}
	if (pr[0] == 3 && (m == 1 || pr[1] != 0))
		return false;
	if (pr[m - 1] == 3 && (m == 1 || pr[m - 2] != 0))
		return false;
	for (i = 1; i < m - 1; i++)
		if (pr[i] == 3 && pr[i - 1] != 0 && pr[i + 1] != 0)
			return false;
	return true;
}

bool couldbefirst(int p)
{
	if (!couldbe(p))
		return false;
	int i;
	for (i = 0; i < m; i++)
	{
		if (p % 4 == 1)
			return false;
		p /= 4;
	}
	return true;
}

bool couldbelast(int p)
{
	if (!couldbe(p))
		return false;
	int i;
	for (i = 0; i < m; i++)
	{
		if (p % 4 == 2)
			return false;
		p /= 4;
	}
	return true;
}

bool trytomatch(int f, int s)
{
	if (!couldbe(f) || !couldbe(s))
		return false;
	int i, p1, p2;
	for (i = 0; i < m; i++)
	{
		p1 = f % 4;
		p2 = s % 4;
		if ((p1 == 2 && p2 != 0) || (p2 == 1 && p1 != 0))
			return false;
		f /= 4;
		s /= 4;
	}
	return true;
}

int main() {
	
	int best, i, j, k;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	if (m > n)
		swap(n, m);
	for (i = 0; i < (1 << (2 * m)); i++)
		freecells[i] = calc_cells(i);
	for (i = 0; i < (1 << (2 * m)); i++)
		for (j = 0; j < (1 << (2 * m)); j++)
			match[i][j] = trytomatch(i, j);
	for (i = 0; i < (1 << (2 * m)); i++)
		ans[0][i] = couldbefirst(i) * freecells[i];
	for (i = 1; i < n; i++)
		for (j = 0; j < (1 << (2 * m)); j++)
			for (k = 0; k < (1 << (2 * m)); k++)
				if (match[j][k])
					ans[i][k] = max(ans[i][k], ans[i - 1][j] + freecells[k]); 
	best = 0;
	for (j = 0; j < (1 << (2 * m)); j++)
		if (couldbelast(j))
			best = max(best, ans[n - 1][j]);
	cout << best;

	return 0;
}