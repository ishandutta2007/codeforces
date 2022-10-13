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
using namespace std;

int a[100100], n, t;

int main()
{
	int x;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) scanf("%d", &x), a[i] = a[i - 1] + x;
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = upper_bound(a + 1, a + n + 1, a[i] + t) - a;
		ans = max(ans, x - 1 - i);
	}
	
	cout << ans << endl;
}