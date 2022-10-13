#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <cstdlib>
using namespace std;

int n;
double ans;
vector <int> a[100100];

void visit(int x, int par, int depth)
{
	ans += 1.0 / depth;
	for (int i = 0; i < int(a[x].size()); i++)
		if (a[x][i] != par)
			visit(a[x][i], x, depth + 1);
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++) cin >> x >> y, a[x].push_back(y), a[y].push_back(x);
	visit(1, 0, 1);
	printf("%.9lf\n", ans);
}