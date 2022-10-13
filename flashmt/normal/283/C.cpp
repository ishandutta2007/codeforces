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
const int BASE = int(1e9) + 7;

int n, a[333], par[333], child[333], f[333][100100], s[100100], d[333];

int main()
{
	//freopen("c.in","r",stdin);
	int Q, T, x, y;
	
	cin >> n >> Q >> T;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	
	while (Q--)
	{
		scanf("%d%d", &x, &y);
		par[y] = x; child[x] = y;
	}
	
	for (int i = 1; i <= n; i++)
		if (!par[i]) 
		{
			d[i] = 1;
			for (int x = child[i]; x; x = child[x])
				d[x] = 1, a[x] += a[par[x]];
		}
		
	// check cycle
	for (int i = 1; i <= n; i++)
		if (!d[i])
		{
			puts("0");
			return 0;
		}

	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= T; j++)
			if (!child[i]) f[i][j] = f[i - 1][j];
			
		for (int j = 0; j <= T; j++)
		{
			if (j < a[i]) s[j] = f[i - 1][j];
			else
			{
				f[i][j] += s[j % a[i]];
				f[i][j] %= BASE;
				s[j % a[i]] += f[i - 1][j];
				s[j % a[i]] %= BASE;
			}
		}
	}
		
	cout << f[n][T] << endl;
}