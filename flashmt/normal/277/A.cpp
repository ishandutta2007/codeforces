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

int known[111], m, n, a[111][111], d[111];

int get(int x)
{
	return x == d[x] ? x : d[x] = get(d[x]);
}

int main()
{
	int x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> known[i];
		for (int j = 0; j < known[i]; j++) cin >> x, a[i][x] = 1;
	}
	
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int j = 1; j <= m; j++)	
		for (int i = 1; i <= n; i++)
			for (int ii = i + 1; ii <= n; ii++)
				if (a[i][j] && a[ii][j])
					d[get(i)] = get(ii);
					
	int nonZero = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
		if (get(i) == i)
		{
			cnt++;
			if (known[i]) nonZero = 1;
		}
		
	cout << cnt - nonZero << endl;
}