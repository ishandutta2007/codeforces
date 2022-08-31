#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int bintodec(int x)
{
	int ans = 0, p = 1;
	while (x > 0)
	{
		ans += (x%2) * p;
		x /= 2;
		p *= 10;
	}
	return ans;
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int n;
	cin >> n;
	int x = 1, ans = 0;
	while (bintodec(x) <= n)
	{
		ans++;
		x++;
	}
	cout << ans;
	return 0;
}