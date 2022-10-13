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

int f[100100], n;

int get(int x)
{
	int res = 0;
	for (int i = x; i; i -= i & -i) res = max(res, f[i]);
	return res;
}

void update(int x, int val)
{
	for (int i = x; i <= n; i += i & -i) f[i] = max(f[i], val);
}

int main()
{
	int x, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		int F = get(x) + 1;
		ans = max(ans, F);
		update(x, F);
	}
	cout << ans << endl;
}