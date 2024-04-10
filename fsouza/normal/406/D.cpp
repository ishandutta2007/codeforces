#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 100000
#define MAXLOGN 17

typedef long long lint;

using namespace std;

const double E = 1e-9;

int n, logn;
lint x[MAXN], y[MAXN];
int height[MAXN], up[MAXN][MAXLOGN+1];

double angle(int i, int j) {return atan2(y[j] - y[i], x[j] - x[i]);}

int goup(int v, int dist) {
	for (int l = logn; l >= 0; l--)
		if (dist & (1<<l))
			v = up[v][l];
	return v;
}

int lca(int a, int b) {
	if (height[a] < height[b]) swap(a, b);
	a = goup(a, height[a] - height[b]);
	if (a == b) return a;
	for (int l = logn; l >= 0; l--)
		if (up[a][l] != up[b][l])
			a = up[a][l], b = up[b][l];
	return up[a][0];
}

bool higher(int i, int j, int k) {
	return (y[j] - y[i]) * (x[k] - x[i]) > (y[k] - y[i]) * (x[j] - x[i]);
}

int main(int argc, char ** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	logn = __builtin_clz(1) - __builtin_clz(n);
	
	stack<int> st;

	height[n-1] = 0;
	up[n-1][0] = 0;

	for (int i = n-2; i >= 0; i--) {
		int &parent = up[i][0];
		parent = i+1;
		while (!st.empty() && higher(i, st.top(), parent))
			parent = st.top(), st.pop();
		st.push(parent);
		
		height[i] = 1 + height[parent];
	}

	for (int l = 1; l <= logn; l++)
		for (int i = 0; i < n; i++)
			up[i][l] = up[up[i][l-1]][l-1];
	
	int nq;

	scanf("%d", &nq);

	for (int q = 0; q < nq; q++) {
		int a, b;
		cin >> a >> b, a--, b--;
		int res = lca(a, b);
		if (q-1 >= 0) cout << " ";
		cout << res+1;
	}
	cout << endl;

	return 0;
}