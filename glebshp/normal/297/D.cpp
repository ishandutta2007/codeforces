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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int size = 2000;
int n, m, k;

int col[size][size];
char buf1[size][size], buf2[size][size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &m, &k);
	if (k == 1) {
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < 2 * n - 1; i++) {
			scanf("%s", buf1);
			int h = strlen(buf1[i]);
			for (int j = 0; j < h; j++)
				cnt += (buf1[i][j] == 'E');
			sum += h;
		}
		if (cnt * 4 >= sum * 3) {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					printf("1%c", " \n"[j == m - 1]);
			}
		} else {
			printf("NO\n");
		}
		return 0;
	}
	scanf("%s", buf2[0]);
	for (int j = 0; j < n - 1; j++)
		scanf("%s%s", buf1[j + 1], buf2[j + 1]);

	if (n * (m - 1) >= m * (n - 1)) {
		for (int i = 0; i < n; i++) {
			col[i][0] = 1;
			for (int j = 0; j < m - 1; j++)
				if (buf2[i][j] == 'E')
					col[i][j + 1] = col[i][j];
				else
					col[i][j + 1] = 3 - col[i][j];
		}
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++)
				if (buf1[i][j] == 'E')
					cnt += (col[i - 1][j] == col[i][j]);
				else
					cnt += (col[i - 1][j] != col[i][j]);
			if (cnt < m - cnt)
				for (int j = 0; j < m; j++)
					col[i][j] = 3 - col[i][j];
		}
	} else {
		for (int i = 0; i < m; i++) {
			col[0][i] = 1;
			for (int j = 1; j < n; j++)
				if (buf1[j][i] == 'E')
					col[j][i] = col[j - 1][i];
				else
					col[j][i] = 3 - col[j - 1][i];
		}
		for (int i = 1; i < m; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (buf2[j][i - 1] == 'E')
					cnt += (col[j][i - 1] == col[j][i]);
				else
					cnt += (col[j][i - 1] != col[j][i]);
			if (cnt < n - cnt)
				for (int j = 0; j < n; j++)
					col[j][i] = 3 - col[j][i];
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d%c", col[i][j], " \n"[j == m - 1]);
	}

	return 0;
}