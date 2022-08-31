#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int sum(int n, int p)
{
	int res = 0;
	while (n > 0)
	{
		res += n%p;
		n /= p;
	}
	return res;
}

int NOD(int a, int b)
{
	if (b == 0) return a;
	return NOD(b, a%b);
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 2; i < n; ++i)
		res += sum(n, i);
	int d = NOD(res, n-2);
	cout << res/d << '/' << (n-2)/d << '\n';
	return 0;
}