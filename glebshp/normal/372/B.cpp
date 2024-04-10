#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 45;

int ans[size][size][size][size];
char field[size][size];
bool isgood[size][size][size][size];

int sum[size][size];

inline int getsum(int xu, int yu, int xb, int yb) {
	xb++;
	yb++;
	return sum[xb][yb] - sum[xu][yb] - sum[xb][yu] + sum[xu][yu];
}

int n, m, q;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 0; i < n; i++)
		scanf("%s", field[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (field[i][j] == '1');
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int p = i; p < n; p++)
				for (int h = j; h < m; h++)
					isgood[i][j][p][h] = (getsum(i, j, p, h) == 0);

	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			for (int p = i; p < n; p++)
				for (int h = j; h < m; h++) {
					ans[i][j][p][h] = 0;
					if (i == p && j == h) {
						ans[i][j][p][h] = isgood[i][j][p][h];
					}
					if (i == p && h > j) {
						ans[i][j][p][h] = ans[i][j + 1][p][h] + ans[i][j][p][h - 1] - ans[i][j + 1][p][h - 1] + isgood[i][j][p][h]; 
					}
					if (p > i && j == h) {
						ans[i][j][p][h] = ans[i + 1][j][p][h] + ans[i][j][p - 1][h] - ans[i + 1][j][p - 1][h] + isgood[i][j][p][h];
					}
					if (p > i && h > j) {
					//	ans[i][j][p][h] = ans[i + 1][j][p][h] + ans[i][j + 1][p][h] + ans[i][j][p - 1][h] + ans[i][j][p][h - 1] - ans[i + 1][j][p - 1][h] - ans[i][j + 1][p][h - 1] - ans[i + 1][j + 1][p - 1][h - 1] + isgood[i][j][p][h]; 
						ans[i][j][p][h] = ans[i + 1][j][p][h] + ans[i][j + 1][p][h] - ans[i + 1][j + 1][p][h];
						for (int ptr1 = i; ptr1 <= p; ptr1++)
							for (int ptr2 = j; ptr2 <= h; ptr2++)
								ans[i][j][p][h] += isgood[i][j][ptr1][ptr2];
					}
				}


	int a, b, c, d;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--, b--, c--, d--;
		printf("%d\n", ans[a][b][c][d]);
	}

	return 0;
}