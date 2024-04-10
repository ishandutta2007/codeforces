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
const int size = 23;
const int degsize = 30;
const long long inf = (long long) 1e18;

long long ans[size + 1][2 * size + 1];
int n, m;
long long a[size], b[size];
long long deg[degsize][size + 1][2 * size + 1];
long long cans[degsize][size + 1][2 * size + 1];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	for (int i = 0; i <= size; i++)
		for (int j = 0; j <= 2 * size; j++)
			ans[i][j] = inf;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < (1 << n); i++) {
		int pt = 0;
		int mn = 0;
		long long cost = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				pt--;
				cost += b[j];
			} else {
				pt++;
				cost += a[j];
			}
			mn = min(mn, pt);
		}

		ans[-mn][pt + size] = min(ans[-mn][pt + size], cost);
	}

	for (int i = 0; i <= size; i++)
		for (int j = 0; j <= 2 * size; j++)
			deg[1][i][j] = ans[i][j];
	for (int d = 2; d <= degsize; d++)
		for (int i = 0; i <= size; i++)
			for (int j = 0; j <= 2 * size; j++) {
				deg[d][i][j] = inf;
			}
	int ti, tj;
	for (int d = 1; d < degsize - 1; d++) {
		for (int i1 = 0; i1 <= size; i1++)
			for (int j1 = 0; j1 <= 2 * size; j1++)
				for (int i2 = 0; i2 <= size; i2++)
					for (int j2 = 0; j2 <= 2 * size; j2++) {
						ti = max(i1, size - j1 + i2);
						tj = j1 + j2 - 2 * size;
						//if (ti == 0 && tj == 0) {
						//	cout << deg[d][i1][j1] << ' ' << deg[d][i2][j2] << endl;
						//}

						if (ti <= size && abs(tj) <= size) {
							deg[d + 1][ti][tj + size] = min(deg[d + 1][ti][tj + size], deg[d][i1][j1] + deg[d][i2][j2]);
							//if (ti == 0 && tj == 0)
							//	cout << deg[d + 1][ti][tj + size] << endl;
						}
					}
	}

	for (int i = 0; i < degsize; i++)
		for (int j = 0; j <= size; j++)
			for (int k = 0; k <= 2 * size; k++)
				cans[i][j][k] = inf;
	cans[0][0][size] = 0;

	for (int d = 0; d < degsize - 1; d++) {
		if ((m >> d) & 1) {
			for (int i1 = 0; i1 <= size; i1++)
				for (int j1 = 0; j1 <= 2 * size; j1++)
					for (int i2 = 0; i2 <= size; i2++)
						for (int j2 = 0; j2 <= 2 * size; j2++) {
							ti = max(i1, size - j1 + i2);
							tj = j1 + j2 - 2 * size;
							if (ti <= size && abs(tj) <= size)
								cans[d + 1][ti][tj + size] = min(cans[d + 1][ti][tj + size], cans[d][i1][j1] + deg[d + 1][i2][j2]);
						}
		} else {
			for (int j = 0; j <= size; j++)
				for (int k = 0; k <= 2 * size; k++)
					cans[d + 1][j][k] = cans[d][j][k];
		}
	}

	cout << cans[degsize - 1][0][size] << endl;

	return 0;
}