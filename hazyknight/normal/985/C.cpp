#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

long long n,k,l;
long long a[100005];
long long ans,MIN = (1 << 30) - 1;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> l;
	for (int i = 1;i <= n * k;i++)
	{
		cin >> a[i];
		MIN = min(MIN,a[i]);
	}
	sort(a + 1,a + n * k + 1);
	MIN += l;
	int st = n * k;
	for (int i = 1;i <= n * k;i++)
		if (a[i] > MIN)
		{
			st = i - 1;
			break;
		}
	if (st < n)
	{
		cout << 0 << endl;
		return 0;
	}
	int j = 1;
	for (int i = 1;i <= n;i++)
	{
		ans += a[j];
		j = min(j + k,st - n + i + 1);
	}
	cout << ans << endl;
	return 0;
}