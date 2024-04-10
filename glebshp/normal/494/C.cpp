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
#define taskname "task_c"

const double pi = acos(-1.0);
const int lsize = 200 * 1000 + 100;
const int ssize = 5100;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const double eps = 1e-50;

int rmq[rms + 1];
int a[lsize];
vector <int> vertex[ssize];
int n, q;
int lb[ssize], rb[ssize];
int mx[ssize];
double p[ssize];
double ans[ssize][ssize];
int deep[ssize];

int rss(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i)
		return 0;
	if (lb >= i && rb <= j)
		return rmq[v];
	return max(rss(v * 2, lb, (lb + rb) / 2, i, j), rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j));
}

void dfs(int v) {
	deep[v] = 1;
	ans[v][0] = 1.0;
	ans[v][1] = 0.0;

	for (int i = 0; i < (int) vertex[v].size(); i++) {
		int tg = vertex[v][i];
		dfs(tg);
		deep[v] = max(deep[v], deep[tg] + 1);

		int diff = mx[v] - mx[tg];
		for (int j = 0; j <= deep[tg] - diff; j++) {
			ans[v][j] = 1.0 - (1.0 - ans[v][j]) * (1.0 - ans[tg][j + diff]);
		}
	}

	for (int i = deep[v]; i >= 1; i--)
		ans[v][i] = ans[v][i] * (1 - p[v]) + ans[v][i - 1] * p[v];
	for (int i = 0; i <= deep[v]; i++)
		if (ans[v][i] < eps)
			ans[v][i] = 0.0;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &q);
	lb[0] = 1;
	rb[0] = n;
	p[0] = 0.0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		rmq[hrms + 1 + i] = a[i];
	}
	for (int i = hrms - 1; i >= 1; i--)
		rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
	
	mx[0] = rss(1, 1, hrms + 1, 1, n);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%lf", &lb[i], &rb[i], &p[i]);
		mx[i] = rss(1, 1, hrms + 1, lb[i], rb[i]);
	}
	for (int i = 1; i <= q; i++)
		for (int j = 1; j < q; j++) {
			if (rb[j] - lb[j] < rb[j + 1] - lb[j + 1]) {
				swap(lb[j], lb[j + 1]);
				swap(rb[j], rb[j + 1]);
				swap(p[j], p[j + 1]);
				swap(mx[j], mx[j + 1]);
			}
		}
	for (int i = 1; i <= q; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (lb[j] <= lb[i] && rb[j] >= rb[i]) {
				vertex[j].pb(i);
				break;
			}
		}
	}

	dfs(0);
	double rans = 0.0;
	for (int i = 0; i < deep[0]; i++) {
		rans += (mx[0] + i) * (ans[0][i] - ans[0][i + 1]);
	}

	cout.precision(20);
	cout << rans << endl;

	return 0;
}