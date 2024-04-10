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
const int size = 200 * 1000;
const long long inf = (long long) 1e18;

long long val[size];
vector <int> vertex[size];
int n;
long long ans[size];
long long step[size];
long long sum = 0;

long long nod(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

void dfs(int v, int fr) {
	int deg = 0;
	long long mn = 0;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			deg++;
			dfs(vertex[v][i], v);
			long long d = nod(mn, step[vertex[v][i]]);
			if (mn == 0)
				mn = step[vertex[v][i]];
			else {
				if (mn / d >= inf / step[vertex[v][i]]) {
					cout << sum << endl;
					exit(0);
				}
				mn = mn  / d * step[vertex[v][i]];
			}
		}
	}
	if (deg == 0) {
		ans[v] = val[v];
		step[v] = 1;
	} else {
		long long vl = inf;
		for (int i = 0; i < (int) vertex[v].size(); i++) {
			if (vertex[v][i] != fr) {
				vl = min(vl, ans[vertex[v][i]] / mn);
			}
		}
		ans[v] = vl * mn * deg;
		step[v] = deg * mn;
	}
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &val[i]);
		sum += val[i];
	}
	int v, u;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;
		vertex[u].pb(v);
		vertex[v].pb(u);
	}

	dfs(0, -1);
	cout << sum - ans[0] << endl;

	return 0;
}