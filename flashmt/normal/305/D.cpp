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
const int BASE = 1000000007;
const int oo = 27081993;

int has[1000100], n, k, p2[1000100], s[1000100];

int main()
{
	for (int i = 0; i <= 1000000; i++) p2[i] = i ? p2[i - 1] * 2 % BASE : 1;
	
	int x, y, m, minHas = oo, maxHas = -oo;
	cin >> n >> m >> k;
	while (m--)
	{
		scanf("%d%d", &x, &y);
		if (y - x == 1) continue;
		
		if (y - x != k + 1 || has[x % (k + 1)])
		{
			puts("0"); return 0;
		}
		
		has[x % (k + 1)] = 1;
		minHas = min(minHas, x);
		maxHas = max(maxHas, x);
	}
	
	if (maxHas - minHas > k) 
	{
		puts("0"); return 0;
	}
	
	int leftBound = max(1, maxHas - k), rightBound = min(n - k - 1, minHas + k);
	
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1];
		if (i + k + 1 <= n && !has[i % (k + 1)]) s[i]++;
	}
	
	long long ans = 1;
	for (int i = leftBound; i <= rightBound; i++)
		if (!has[i % (k + 1)])
		{
			int cnt = s[min(rightBound, i + k)] - s[i];
			ans += p2[cnt];
			ans %= BASE;
		}
		
	cout << ans << endl;
}