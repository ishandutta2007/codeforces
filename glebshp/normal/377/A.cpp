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
#define taskname "problem_a"

const double pi = acos(-1.0);
const int size = 1000;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

char field[size][size];
bool used[size][size];

int n, m, k;

bool onfield(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
	used[x][y] = true;
	if (k < 0) {
		field[x][y] = '.';
		k++;
	}
	for (int i = 0; i < 4; i++) {
		if (onfield(x + px[i], y + py[i]) && !used[x + px[i]][y + py[i]] && field[x + px[i]][y + py[i]] == 'X')
			dfs(x + px[i], y + py[i]);
	}
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", field[i]);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (field[i][j] == '.') {
				field[i][j] = 'X';
				k--;
			}
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 'X' && k < 0) {
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", field[i]);
	}

	return 0;
}