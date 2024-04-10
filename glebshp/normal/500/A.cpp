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
#define taskname "task_a"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

int a[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));

	int n, t;

	scanf("%d%d", &n, &t);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", &a[i]);
	a[n - 1] = 0;

	int cur = 0;
	t--;

	while (cur < t) {
		cur += a[cur];
	}

	if (cur == t)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}