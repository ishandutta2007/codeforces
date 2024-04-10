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
const int size = 100 * 1000;

int deg[size], xr[size];
int n;
bool used[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &deg[i], &xr[i]);

	queue <int> q;
	vector <pair <int, int> > ans;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1) {
			q.push(i);
		}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (deg[v] == 0)
			continue;
		ans.pb(mp(v, xr[v]));

		deg[v]--;
		deg[xr[v]]--;
		xr[xr[v]] ^= v;
		
		if (deg[xr[v]] == 1)
			q.push(xr[v]);
		xr[v] = 0;

	}

	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d\n", ans[i].fs, ans[i].sc);

	return 0;
}