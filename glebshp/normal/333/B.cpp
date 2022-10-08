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
const int size = 2000;

bool used1[size], used2[size];

int main() {
	int n, m, x, y;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		used1[i] = true;
		used2[i] = true;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		used1[x] = false;
		used2[y] = false;
	}

	int ans = 0;
	if (n & 1) {
		ans += used1[n / 2] || used2[n / 2];
	}
	for (int i = 1; i < n / 2; i++) {
		//cout << used1[i] + used2[i] + used1[n - i - 1] + used2[n - i - 1] << endl;
		ans += used1[i] + used2[i] + used1[n - i - 1] + used2[n - i - 1];
	}

	cout << ans << endl;

	return 0;
}