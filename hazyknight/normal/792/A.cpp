#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int a[200005];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int MIN = 2000000001,cnt = 0;
	for (int i = 2;i <= n;i++)
	{
		if (MIN > a[i] - a[i - 1])
			MIN = a[i] - a[i - 1],cnt = 0;
		if (MIN == a[i] - a[i - 1])
			cnt++;
	}
	cout << MIN << ' ' << cnt << endl;
	return 0;
}