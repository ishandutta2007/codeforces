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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int rms = (1 << 20) - 1;
const int hrms = rms / 2;
const int size = 1000 * 1000 + 100;

int rmq[rms + 1];
int md[rms + 1];
int n;

int tm = 0;
int intime[size], outtime[size];
vector <int> vertex[size];

void dfs(int v, int fr) {
	intime[v] = tm++;
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (vertex[v][i] != fr)
			dfs(vertex[v][i], v);
	outtime[v] = tm - 1;
}

void change(int ps, int val) {
	ps += hrms;
	rmq[ps] = val;
	while (ps > 1) {
		ps /= 2;
		rmq[ps] = val;
	}
}

void putmod(int v, int lb, int rb, int i, int j, int val) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		md[v] = val;
		return;
	}
	putmod(v * 2, lb, (lb + rb) / 2, i, j, val);
	putmod(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j, val);
}

int rss(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i)
		return 0;
	if (lb >= i && rb <= j)
		return rmq[v];
	return max(rss(v * 2, lb, (lb + rb) / 2, i, j), rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j));
}

int getmod(int v) {
	v += hrms;
	int mx = 0;
	while (v > 0) {
		mx = max(mx, md[v]);
		v /= 2;
	}

	return mx;
}

int main() {
	int v, u;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;
		vertex[v].pb(u);
		vertex[u].pb(v);
	}

	int q;

	dfs(0, -1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &v, &u);
		u--;
		if (v == 1) {
			putmod(1, 1, hrms + 1, intime[u] + 1, outtime[u] + 1, i + 1);
		}
		if (v == 2) {
			change(intime[u] + 1, i + 1);
		}
		if (v == 3) {
			int d1 = getmod(intime[u] + 1);
			int d2 = rss(1, 1, hrms + 1, intime[u] + 1, outtime[u] + 1);
			//cout << d1 << ' ' << d2 << endl;
			if (d1 > d2)
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}