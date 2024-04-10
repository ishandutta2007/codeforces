#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

long long n,u,ok;
long long e[100005];
long long ans1,ans2 = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> u;
	for (int i = 1;i <= n;i++)
		cin >> e[i];
	for (int i = 1;i < n - 1;i++)
	{
		int low = i + 2,high = n;
		while (low < high)
		{
			int mid = (low + high + 1) >> 1;
			if (e[mid] - e[i] > u)
				high = mid - 1;
			else
				low = mid;
		}
		if (e[low] - e[i] > u)
			continue;
		if (low == i + 1)
			continue;
		ok = 1;
		if (ans1 * (e[low] - e[i]) < (e[low] - e[i + 1]) * ans2)
		{
			ans1 = e[low] - e[i + 1];
			ans2 = e[low] - e[i];
		}
	}
	if (!ok)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(10) << (long double)ans1 / (long double)ans2 << endl;
	return 0;
}