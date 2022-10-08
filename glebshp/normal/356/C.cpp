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
#define taskname "problem_c"

const double pi = acos(-1.0);
const int size = 40;
const int inf = 1000 * 1000 * 1000;

int n;
int tot = 0, sum = 0;
int c[5];
int ans[size][size][size][size];

inline int get(int a, int b, int c, int d) {
	if (a < 0 || b < 0 || c < 0 || d < 0)
		return inf;
	return ans[a][b][c][d];
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	int val;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		c[val]++;
		tot += val;
		if (val <= 2)
			sum += val;
	}

	if (tot == 1 || tot == 2 || tot == 5) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				for (int p = 0; p < size; p++) {
					if (i == 0 && j == 0) {
						ans[i][j][k][p] = 0;
						continue;
					}
					ans[i][j][k][p] = inf;
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 4, j, k, p) + 3);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 2, j - 1, k, p) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i, j - 2, k, p) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 1, j, k - 1, p) + 1);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 3, j, k, p) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 1, j - 1, k, p) + 1);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i, j - 1, k, p - 1) + 1);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 2, j, k, p - 1) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i, j - 3, k, p) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i, j - 1, k - 2, p) + 2);
					ans[i][j][k][p] = min(ans[i][j][k][p], get(i - 1, j, k, p - 2) + 2);
				}

	int la = 0;
	
	while (c[1] > 0 && c[2] > 0) {
		if (c[1] < size && c[2] < size) {
			c[3] = min(c[3], size - 1);
			c[4] = min(c[4], size - 1);

			cout << ans[c[1]][c[2]][c[3]][c[4]] + la << endl;

			return 0;
		}

		c[1]--;
		c[2]--;
		c[3]++;
		la++;
	}
	while (c[2] >= size) {
		c[2] -= 3;
		c[3] += 2;
		la += 2;
	}
	
	while (c[1] >= size) {
		c[1] -= 3;
		c[3]++;
		la += 2;
	}


	c[3] = min(c[3], size - 1);
	c[4] = min(c[4], size - 1);

	cout << ans[c[1]][c[2]][c[3]][c[4]] + la << endl;

	return 0;
}