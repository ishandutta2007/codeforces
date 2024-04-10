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
#define taskname "task_c"

const double pi = acos(-1.0);

const int size = 10 * 1000 + 100;

int n, m, w[size], b[size];
int lst[size];
bool used[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		b[i]--;
	}
	
	for (int i = 0; i < n; i++)
		lst[i] = -1;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			used[j] = false;
		for (int j = lst[b[i]] + 1; j < i; j++)
			used[b[j]] = true;
		used[b[i]] = false;

		for (int j = 0; j < n; j++)
			if (used[j])
				ans += w[j];
		lst[b[i]] = i;
	}

	printf("%d\n", ans);
	
	return 0;
}