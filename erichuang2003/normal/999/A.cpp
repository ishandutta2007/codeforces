#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n,k,ans;
int a[105];

bool mark[105];

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		if (a[i] > k)
			break;
		mark[i] = true;
	}
	for (int i = n;i >= 1;i--)
	{
		if (a[i] > k)
			break;
		mark[i] = true;
	}
	for (int i = 1;i <= n;i++)
		ans += mark[i];
	cout << ans << endl;
	return 0;
}