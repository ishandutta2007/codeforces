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
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;
const int inf = 1000 * 1000 * 1000 + 100;

int n, s, l;
int ans[size];
int a[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &s, &l);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		ans[i] = inf;
	ans[0] = 0;

	int p = 0;
	set <pair <int, int> > nums;
	set <pair <int, int> > ansv;

	for (int i = 0; i < n; i++) {
		nums.insert(mp(a[i], i));
		if (i - l + 1 >= p)
			ansv.insert(mp(ans[i - l + 1], i - l + 1));
		while (nums.rbegin()->fs - nums.begin()->fs > s) {
			nums.erase(mp(a[p], p));
			ansv.erase(mp(ans[p], p));
			p++;
		}

		if (!ansv.empty()) {
			ans[i + 1] = ansv.begin()->fs + 1;
		}
	}

	if (ans[n] > inf / 2)
		cout << -1 << endl;
	else
		cout << ans[n] << endl;

	return 0;
}