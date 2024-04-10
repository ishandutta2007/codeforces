#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795
#define double long double

const int size = 500;
const double eps = 1e-12;

double p[size], mat[size][size], bk[size][size];
int deg[size], num[size][size], n;
bool way[size][size];

double ctg(int s, int f)
{
	if (!way[s][f])
		return 0;
	if (s == f)
		return p[s];
	else
		return (1 - p[s]) / deg[s];
}

double chance_to_move(int s1, int f1, int s2, int f2)
{
	if (s1 == f1)
		return (s1 == s2) && (f1 == f2);
	return ctg(s1, s2) * ctg(f1, f2);
}

void build_matrix()
{
	int h, i, j, p, q, cnt = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			num[i][j] = cnt++;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			mat[num[i][j]][num[i][j]] = 1;
	for (h = 0; h < n; h++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (p = 0; p < n; p++)
					for (q = 0; q < n; q++)
						if (p == q)
							bk[num[i][j]][h] += chance_to_move(i, j, p, q) * (p == h);
						else
							if (h == 0)
								mat[num[i][j]][num[p][q]] -= chance_to_move(i, j, p, q);
}

void process()
{
	int i, j, p, q, lm = n * n;
	double mn;
	for (i = 0; i < lm; i++)
	{
		
		for (j = 0; j < lm; j++)
			for (p = 0; p < lm; p++)
				if (fabs(mat[j][p]) < eps)
					mat[j][p] = 0;
		
		for (j = 0; j < lm; j++)
			if (fabs(mat[i][j]) > 0)
			{
				for (p = i + 1; p < lm; p++)
					if (fabs(mat[p][j]) > 0)
					{
						mn = mat[p][j] / mat[i][j];
						for (q = 0; q < lm; q++)
							mat[p][q] -= mat[i][q] * mn;
						for (q = 0; q < n; q++)
							bk[p][q] -= bk[i][q] * mn;
					}
				break;
			}
	}
	for (i = lm - 1; i >= 0; i--)
		for (j = 0; j < lm; j++)
			if (fabs(mat[i][j]) > 0)
			{
				for (p = 0; p < n; p++)
					bk[i][p] /= mat[i][j];
				for (q = i - 1; q >= 0; q--)
					if (fabs(mat[q][j]) > 0)
					{
						for (p = 0; p < n; p++)
							bk[q][p] -= bk[i][p] * mat[q][j];
						mat[q][j] = 0;
					}
				break;
			}
}

int main()
{
	int m, a, b, s, f, i, j;

	cout.precision(20);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n >> m;
	cin >> a >> b;
	a--, b--;
	for (i = 0; i < m; i++)
	{
		cin >> s >> f;
		s--, f--;
		way[s][f] = true;
		way[f][s] = true;
		deg[s]++, deg[f]++;
	}
	for (i = 0; i < n; i++)
		way[i][i] = true;
	for (i = 0; i < n; i++)
		cin >> p[i];

	build_matrix();
	process();
	for (i = 0; i < n; i++)
		cout << bk[num[a][b]][i] << ' ' << endl;

    return 0;
}