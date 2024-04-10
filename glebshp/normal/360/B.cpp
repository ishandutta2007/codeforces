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
const int size = 3000;
const int inf = 2 * 1000 * 1000 * 1000;

int f[size];
int mas[size];
int n, k;
int cost[size][size];

bool check(int val) {
	for (int i = 0; i < n; i++) {
		f[i] = i;
		for (int j = 0; j < i; j++)
			if (cost[j][i] <= val)
				f[i] = min(f[i], f[j] + i - j - 1);
	}
	int best = n;
	for (int i = 0; i < n; i++)
		best = min(best, f[i] + n - i - 1);

	return best <= k;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cost[i][j] = (abs(mas[i] - mas[j]) + j - i - 1) / (j - i);
	int lb = 0;
	int rb = inf;
	while (lb < rb) {
		int mid = lb + (rb - lb) / 2;
		if (check(mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	cout << lb << endl;

	return 0;
}