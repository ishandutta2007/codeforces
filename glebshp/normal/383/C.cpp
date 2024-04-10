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
#define taskname "problem_c"

const double pi = acos(-1.0);
const int size = 300 * 1000;
const int rms = (1 << 21) - 1;
const int hrms = rms / 2;

int n, m;
int a[size];
int md[2][rms + 1];
int intime[size];
int mytime[size];
int outtime[size];
int vtp[size];

void update(int tp, int v, int i, int j, int lb, int rb, int mdv) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		md[tp][v] += mdv;
		return;
	}

	update(tp, v * 2, i, j, lb, (lb + rb) / 2, mdv);
	update(tp, v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb, mdv);
}

vector <int> vertex[size];

int gcnt = 1;

void dfs(int v, int fr, int c) {
	intime[v] = gcnt++;
	mytime[v] = gcnt++;
	vtp[v] = c;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			dfs(vertex[v][i], v, 1 - c);
		}
	}

	outtime[v] = gcnt++;
}

int getvalue(int v) {
	int tp = vtp[v];
	int p = mytime[v] + hrms;

	//cout << p << endl;
	int sum = a[v];
	while (p > 0) {
		sum += md[tp][p];
		p /= 2;
	}

	return sum;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int v, u;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;
		vertex[v].pb(u);
		vertex[u].pb(v);
	}

	dfs(0, -1, 0);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &v, &u);
			v--;
			update(vtp[v], 1, intime[v], outtime[v], 1, hrms + 1, u);
			update(1 - vtp[v], 1, intime[v], outtime[v], 1, hrms + 1, -u);
		} else {
			scanf("%d", &v);
			printf("%d\n", getvalue(v - 1));
		}
	}

	return 0;
}