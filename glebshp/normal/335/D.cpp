#pragma comment(linker, "/STACK:1000000000")
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
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 100 * 1000;
const int s_size = 3010;
const int inf = 1000 * 1000 * 1000;

int xc1[size], yc1[size], xc2[size], yc2[size];
int n;

int nums[s_size][s_size];
int cover[s_size][s_size];
int val1[s_size][s_size];
int val2[s_size][s_size];
int help[s_size][s_size];
bool used[size];

inline int getsum(int xd, int yd, int xu, int yu) {
	return cover[xu][yu] - cover[xd][yu] - cover[xu][yd] + cover[xd][yd];
}

void printsol(int x1, int y1, int x2, int y2) {
	for (int i = x1 + 1; i <= x2; i++)
		for (int j = y1 + 1; j <= y2; j++)
			used[nums[i][j]] = true;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += used[i];
	printf("YES %d\n", cnt);
	for (int i = 0; i < n; i++)
		if (used[i])
			printf("%d ", i + 1);
	printf("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	for (int i = 0; i < s_size; i++)
		for (int j = 0; j < s_size; j++) {
			nums[i][j] = -1;
			cover[i][j] = 0;
			val1[i][j] = inf;
			val2[i][j] = inf;
		}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &xc1[i], &yc1[i], &xc2[i], &yc2[i]);
		for (int x = xc1[i] + 1; x <= xc2[i]; x++)
			for (int y = yc1[i] + 1; y <= yc2[i]; y++) {
				cover[x][y] = 1;
				nums[x][y] = i;
			}
	}

	for (int i = 0; i < s_size; i++)
		for (int j = 0; j < s_size; j++)
			if (nums[i][j] == -1) {
				val2[i][j] = 0;
				if (i > 0 && j > 0)
					val1[i - 1][j - 1] = 0;
			}
	for (int i = 1; i < s_size; i++)
		for (int j = 1; j < s_size; j++) {
			cover[i][j] = cover[i - 1][j] + cover[i][j - 1] - cover[i - 1][j - 1] + cover[i][j];
		}

	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = 1; i < s_size; i++)
		for (int j = 1; j < s_size; j++) {
			help[i][j] = help[i - 1][j] + 1;
			while (getsum(i - help[i][j], j - help[i][j], i, j) < help[i][j] * help[i][j])
				help[i][j]--;
			val2[i][j] = min(val2[i][j], help[i][j]);
		}
	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = 1; i < s_size; i++)
		for (int j = 1; j < s_size; j++) {
			if (nums[i][j] != -1 && nums[i][j] == nums[i + 1][j])
				help[i][j] = 0;
			else
				help[i][j] = help[i][j - 1] + 1;
			val2[i][j] = min(val2[i][j], help[i][j]);
		}
	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = 1; i < s_size; i++)
		for (int j = 1; j < s_size; j++) {
			if (nums[i][j] != -1 && nums[i][j] == nums[i][j + 1])
				help[i][j] = 0;
			else
				help[i][j] = help[i - 1][j] + 1;
			val2[i][j] = min(val2[i][j], help[i][j]);
		}

	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = s_size - 2; i >= 0; i--)
		for (int j = s_size - 2; j >= 0; j--) {
			help[i][j] = help[i][j + 1] + 1;
			while (getsum(i, j, i + help[i][j], j + help[i][j]) != help[i][j] * help[i][j])
				help[i][j]--;
			val1[i][j] = min(val1[i][j], help[i][j]);
		}

	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = s_size - 2; i >= 0; i--)
		for (int j = s_size - 2; j >= 0; j--) {
			if (nums[i][j + 1] != -1 && nums[i][j + 1] == nums[i + 1][j + 1])
				help[i][j] = 0;
			else
				help[i][j] = help[i][j + 1] + 1;
			val1[i][j] = min(val1[i][j], help[i][j]);
		}

	memset(help, 0, sizeof(int) * s_size * s_size);
	for (int i = s_size - 2; i >= 0; i--)
		for (int j = s_size - 2; j >= 0; j--) {
			if (nums[i + 1][j] != -1 && nums[i + 1][j] == nums[i + 1][j + 1])
				help[i][j] = 0;
			else
				help[i][j] = help[i + 1][j] + 1;
			val1[i][j] = min(val1[i][j], help[i][j]);
		}
	for (int i = -s_size + 1; i < s_size; i++) {
		int x = max(i, 0);
		int y = -min(i, 0);
		vector <int> st;
		for (int p = 0; x + p < s_size && y + p < s_size; p++) {
			while (!st.empty() && st.back() >= p - val2[x + p][y + p])
				if (val1[x + st.back()][y + st.back()] >= p - st.back()) {
					printsol(x + st.back(), y + st.back(), x + p, y + p);
					return 0;
				} else {
					st.pop_back();
				}
			st.pb(p);
		}
	}

	printf("NO\n");

    return 0;
}