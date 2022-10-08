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
const int size = 500 * 1000;
const long long inf = (long long) 1e18;

int a[size];
long long sum[size];
bool used[size];

int main() {
    int n;
	
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sum[0] = 0;
	long long ans = -inf;
	int lb = -1;
	int rb = -1;
	map <int, int> lst;
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + max(a[i - 1], 0);
	}

	lst[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (lst[a[i]] != 0) {
			long long cans = sum[i] - sum[lst[a[i]] - 1];
			if (a[i] < 0)
				cans += 2 * a[i];
			else
				cans += a[i];
			if (cans > ans) {
				ans = cans;
				lb = lst[a[i]] - 1;
				rb = i;
			}
		} else {
			lst[a[i]] = i + 1;
		}
	}

	for (int i = 0; i < n; i++)
		used[i] = (i >= lb && i <= rb && (i == lb || i == rb || a[i] > 0));
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += !used[i];
	printf("%I64d %d\n", ans, cnt);
	for (int i = 0; i < n; i++)
		if (!used[i])
			printf("%d ", i + 1);

    return 0;
}