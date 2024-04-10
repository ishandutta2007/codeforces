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
const int size = 3000;
const long long mdl = 1000 * 1000 * 1000 + 7;

long long ans[size][size];
int a[size];

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	int ac = 0, bc = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) 
			ac++;
		else
			if (a[a[i] - 1] == -1)
				bc++;
	}

	ans[0][0] = 1;
	for (int i = 1; i <= ac; i++) {
		ans[i][i] = (ans[i - 1][i - 1] * i) % mdl;
		for (int j = i - 1; j >= 0; j--) {
			ans[i][j] = ans[i - 1][j] * j;
			if (i - j >= 2)
				ans[i][j] += ans[i - 1][j + 1] * (i - j - 1);
			ans[i][j] %= mdl;
		}
	}

	cout << ans[ac][bc] << endl;

	return 0;
}