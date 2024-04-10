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

int n, a[200200], color[200200][2], cyclic[200200][2];
long long f[200200][2];

long long go(int x, int z)
{
	if (x < 1 || x > n) return 0;
	if (x == 1 || color[x][z] == 1) return -1;
	if (color[x][z] == 2) return f[x][z];
	
	color[x][z] = 1;
	
	int y;
	if (!z) y = x - a[x];
	else y = x + a[x];
		
	long long u = go(y, z ^ 1);
	if (u < 0)
	{
		cyclic[x][z] = 1;
		f[x][z] = -1;
		color[x][z] = 2;
		return -1;
	}
	f[x][z] = u + a[x];
	
	color[x][z] = 2;
	return f[x][z];
}

int main()
{
	//freopen("b.in","r",stdin);
	cin >> n;
	for (int i = 2; i <= n; i++) scanf("%d", a + i);
		
	for (int i = 2; i <= n; i++)
	{
		long long val = go(i, 0) + i - 1;
		if (cyclic[i][0]) puts("-1");
		else cout << val << endl;
	}
}