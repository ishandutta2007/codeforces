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

int b, d, next[111][256], m, n;
long long period[111][55];
string a, c;

int canObtain(long long p)
{
	long long cur = 0;
	for (int i = 40; i >= 0; i--)
		if (p >> i & 1)
		{
			cur += period[cur % m][i];
			p ^= 1LL << i;
			cur++;
		}
	return cur <= 1LL * m * b;
}

int main()
{
	cin >> b >> d >> a >> c;
	m = a.size(), n = c.size();
	
	set <char> s;
	for (int i = 0; i < m; i++) s.insert(a[i]);
	for (int i = 0; i < n; i++)
		if (!s.count(c[i]))
		{
			puts("0");
			return 0;
		}
		
	memset(next, -1, sizeof(next));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			char ch = a[(i + j) % m];
			if (next[i][ch] < 0) next[i][ch] = j;
		}
		
	for (int i = 0; i < m; i++)
	{
		int cur = 0;
		for (int j = 0; j < n; j++) cur += next[(cur + i) % m][c[j]] + 1;
		period[i][0] = cur - 1;
	}
	
	for (int j = 0; j < 40; j++)
		for (int i = 0; i < m; i++)	
			period[i][j + 1] = period[i][j] + 1 + period[(period[i][j] + 1 + i) % m][j];
			
	int low = 1, high = m * b / (n * d), ans = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (canObtain(1LL * mid * d)) ans = mid, low = mid + 1;
		else high = mid - 1;
	}
	
	cout << ans << endl;
}