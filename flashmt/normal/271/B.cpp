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

int p[111111], row[555], col[555];

int isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

int main()
{
	int m, n, x;
	for (int i = 2; i < 111111; i++)
		if (isPrime(i)) p[i] = i;
	for (int i = 111110; i; i--) 
		if (!p[i]) p[i] = p[i + 1];
		
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &x);
			row[i] += p[x] - x;
			col[j] += p[x] - x;
		}
	
	int ans = 1 << 29;
	for (int i = 0; i < m; i++) ans = min(ans, row[i]);
	for (int i = 0; i < n; i++) ans = min(ans, col[i]);
	cout << ans << endl;
}