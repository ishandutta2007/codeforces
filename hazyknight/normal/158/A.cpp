#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,k;
int a[55];

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
    reverse(a + 1,a + n + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] >= a[k] && a[i])
			ans++;
	cout << ans << endl;
	return 0;
}