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
#define taskname "task_d"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

vector <int> vertex[size];
long long subsize[size];
int n;
int v[size], u[size];
long long cost[size];
double prob[size];

long long triples(long long s) {
	if (s < 3)
		return 0;
	else
		return s * (s - 1) * (s - 2) / 6;
}

void dfs(int v, int fr) {
	subsize[v] = 1;
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (vertex[v][i] != fr) {
			dfs(vertex[v][i], v);
			subsize[v] += subsize[vertex[v][i]];
		}
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%I64d", &v[i], &u[i], &cost[i]);
		v[i]--, u[i]--;
		vertex[v[i]].pb(u[i]);
		vertex[u[i]].pb(v[i]);
	}

	dfs(0, 0);
	double cur = 0.0;

	for (int i = 0; i < n - 1; i++) {
		int cv = v[i];
		if (subsize[u[i]] < subsize[v[i]])
			cv = u[i];
		prob[i] = 1.0 - ((triples(subsize[cv]) + triples(n - subsize[cv]) + 0.0) / triples(n));
		cur += prob[i] * cost[i] * 2.0;
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int r, w;
		scanf("%d%d", &r, &w);
		r--;

		cur -= prob[r] * cost[r] * 2.0;
		cost[r] = w;
		cur += prob[r] * cost[r] * 2.0;

		printf("%.15lf\n", cur);
	}

	return 0;
}