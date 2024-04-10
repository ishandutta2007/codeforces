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
#include <stack>
#include <sstream>
using namespace std;
const int oo = 1 << 29;

int main()
{
	int n, D, a[111] = {0}, x[111], y[111], f[111] = {0}, d[111] = {0};
	
	cin >> n >> D;
	for (int i = 2; i < n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for (int i = 2; i <= n; i++) f[i] = oo;
	int u = 1;
	
	while (u)
	{
		d[u] = 1;
		for (int v = 1; v <= n; v++)
			if (!d[v])
				f[v] = min(f[v], f[u] + D * (abs(x[u] - x[v]) + abs(y[u] - y[v])) - a[v]);
		
		u = 0;
		int best = oo;
		for (int v = 1; v <= n; v++)
			if (!d[v] && f[v] < best)
				best = f[v], u = v;
	}
	
	cout << f[n] << endl;
}