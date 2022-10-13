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
using namespace std;
const int oo = 1 << 29;

int n, m, a[5555], f[5555], g[5555];

int main()
{
	double x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i] >> x;
	
	for (int i = 0; i <= n; i++) f[i] = g[i] = oo;
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i] != j) f[j]++;
			else f[j] = min(g[j], i - 1);
			g[j] = min(g[j - 1], f[j]);
		}
	
	cout << g[m] << endl;
}