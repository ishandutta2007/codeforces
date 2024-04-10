#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m,k,ans;
int a[200005];

bool mark[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	if (k == 1)
	{
		cout << n << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int last = 1,cnt = 1;
	mark[1] = true;
	for (int i = 2;i <= n;i++)
	{
		while (a[i] - a[last] >= m)
			cnt -= mark[last],last++;
		if (cnt + 1>= k)
		{
			mark[i] = false;
			ans++;
		}
		else
		{
			mark[i] = true;
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}