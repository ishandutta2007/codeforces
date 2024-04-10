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
#define taskname "problem_f"

const double pi = acos(-1.0);
const int size = 2000 * 1000;
const int lgs = 22;

int par[lgs][size];
int deep[size];

int liftup(int v, int d) {
	for (int i = lgs - 1; i >= 0; i--)
		if (deep[par[i][v]] >= d) {
			v = par[i][v];
		}

	return v;
}

int getlca(int v, int u) {
	if (deep[v] > deep[u])
		swap(v, u);
	u = liftup(u, deep[v]);
	if (v == u)
		return v;
	for (int i = lgs - 1; i >= 0; i--)
		if (par[i][v] != par[i][u]) {
			v = par[i][v];
			u = par[i][u];
		}

	return par[0][v];
}

int getdist(int v, int u) {
	int lc = getlca(v, u);
	return deep[v] + deep[u] - 2 * deep[lc];
}

int curd = 0;
int curf = 0, curs = 0;
int cnt = 1;

void addvertex(int v) {
	deep[cnt] = deep[v] + 1;
	par[0][cnt] = v;
	for (int i = 1; i < lgs; i++)
		par[i][cnt] = par[i - 1][par[i - 1][cnt]];
	int d = getdist(curf, cnt);
	if (d > curd) {
		curd = d;
		curs = cnt;
	} else {
		d = getdist(curs, cnt);
		if (d > curd) {
			curd = d;
			curf = cnt;
		}
	}

	cnt++;
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	int n = 500 * 1000;
	printf("%d\n", n);
	int lst = 4;
	for (int i = 0; i < n; i++) {
		printf("%d\n", lst);
		lst += 2;
	}

	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	addvertex(0);
	addvertex(0);
	addvertex(0);

	int q, v;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &v);
		v--;
		addvertex(v);
		addvertex(v);
		printf("%d\n", curd);
	}

	return 0;
}