#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int base = 1000000007;

vector <int> d[100100];

long long power(int x, int y)
{
	if (!y) return 1;
	long long res = power(x, y / 2);
	res *= res; res %= base;
	if (y % 2) res *= x, res %= base;
	return res;
}

int main()
{
	int n, a[100100], mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
	sort(a, a + n);
	
	for (int i = 1; i * 2 <= mx; i++)
		for (int j = i * 2; j <= mx; j += i)
			d[j].push_back(i);
		
	long long ans = 1;
	for (int x = 2; x <= mx; x++)
	{
		int D = d[x].size();
		int id = lower_bound(a, a + n, x) - a;
		long long res = power(D + 1, n - id) - power(D, n - id);
		if (res < 0) res += base;

		int last = id;
		for (int i = D - 1; i >= 0; i--)
		{
			id = lower_bound(a, a + n, d[x][i]) - a;
			res = res * power(i + 1, last - id) % base;
			last = id;
		}

		ans = (ans + res) % base;
	}
	
	cout << ans << endl;
}