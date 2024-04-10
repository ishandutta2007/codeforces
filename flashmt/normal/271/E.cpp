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

int primeFactor(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return i;
	return 0;
}

int gcd(int x, int y)
{
	return x && y ? gcd(y, x % y) : x + y;
}

int main()
{
	int n, m, x, g = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &x);
		--x;
		while (x % 2 == 0) x >>= 1; 
		g = gcd(g, x);
	}
	
	long long ans = 0;
	for (int i = 1; i * i <= g; i++)
		if (g % i == 0)
		{
			for (long long d = i; d < m; d <<= 1) ans += m - d;
			if (i * i != g)
				for (long long d = g / i; d < m; d <<= 1) ans += m - d;
		}
		
	cout << ans << endl;
}