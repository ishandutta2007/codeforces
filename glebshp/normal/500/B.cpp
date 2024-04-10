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
const int size = 1000 + 10;

char a[size][size];
int n;
int p[size];
int ans[size];
bool used[size];

vector <int> els;
vector <int> ps;

void dfs(int v) {
	ps.pb(v);
	els.pb(p[v]);
	used[v] = true;
	for (int i = 0; i < n; i++)
		if (a[v][i] == '1' && !used[i])
			dfs(i);
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	for (int i = 0; i < n; i++)
		if (!used[i]) {
			els.clear();
			ps.clear();
			dfs(i);
			sort(els.begin(), els.end());
			sort(ps.begin(), ps.end());

			for (int j = 0; j < (int) els.size(); j++)
				ans[ps[j]] = els[j];
		}

	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i == n - 1]);

	return 0;
}