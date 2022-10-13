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

int m, n, a[200200], d[200200];

int main()
{
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x]++; a[y]++;
	}
	
	for (int i = 1; i <= n; i++) d[a[i]]++;
	
	if (m == n - 1 && d[2] == n - 2 && d[1] == 2) puts("bus topology");
	else
		if (m == n - 1 && d[1] == n - 1 && d[n - 1] == 1) puts("star topology");
		else
			if (m == n && d[2] == n) puts("ring topology");
			else puts("unknown topology");
}