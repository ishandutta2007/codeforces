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

int n,k;
int a[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	if (k == n)
		cout << a[n] << endl;
	else if (k == 0)
	{
		if (a[1] == 1)
			cout << -1 << endl;
		else
			cout << 1 << endl;
	}
	else
	{
		if (a[k] == a[k + 1])
			cout << -1 << endl;
		else
			cout << a[k] << endl;
	}
	return 0;
}