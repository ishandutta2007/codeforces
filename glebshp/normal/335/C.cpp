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
const int size = 200;

int grandi[size][16];
int x[size], y[size];
int r, n;
bool used[size][2];
int mex[size * 16];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> r >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
		used[x[i]][y[i]] = true;
		used[min(r - 1, x[i] + 1)][1 - y[i]] = true;
		used[x[i]][1 - y[i]] = true;
		used[max(0, x[i] - 1)][1 - y[i]] = true;
	}
	for (int i = 0; i < 16; i++) {
		grandi[0][i] = 0;
		int pl = (i & 1) + ((i >> 2) & 1);
		int pr = ((i >> 1) & 1) + ((i >> 3) & 1);
		if (pl == 0 || pr == 0)
			grandi[1][i] = 1;
		else
			grandi[1][i] = 0;
	}

	int hcnt = 1;
	for (int i = 2; i <= r; i++)
		for (int j = 0; j < 16; j++) {
			hcnt++;
			if (!(j & 1))
				mex[grandi[i - 1][(j & 12) + 2]] = hcnt;
			if (!((j >> 1) & 1))
				mex[grandi[i - 1][(j & 12) + 1]] = hcnt;
			if (!((j >> 2) & 1))
				mex[grandi[i - 1][(j & 3) + 8]] = hcnt;
			if (!((j >> 3) & 1))
				mex[grandi[i - 1][(j & 3) + 4]] = hcnt;
			for (int k = 1; k < i - 1; k++) {
				mex[grandi[k][(j & 3) + 8] ^ grandi[i - k - 1][(j & 12) + 2]] = hcnt;
				mex[grandi[k][(j & 3) + 4] ^ grandi[i - k - 1][(j & 12) + 1]] = hcnt;
			}
			grandi[i][j] = 0;
			while (mex[grandi[i][j]] == hcnt)
				grandi[i][j]++;
			//cout << i << ' ' << j << ' ' << grandi[i][j] << endl;
		}
	int ans = 0;
	int i = 0, j = 0;
	while (i < r) {
		if (used[i][0] && used[i][1])
			i++;
		else {
			j = i + 1;
			while (j < r && (!used[j][0] || !used[j][1])) {
				j++;
			}
			ans ^= grandi[j - i][used[i][0] + used[i][1] * 2 + used[j - 1][0] * 4 + used[j - 1][1] * 8];
			i = j;
		}
	}
	if (ans)
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;

	return 0;
}