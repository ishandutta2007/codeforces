#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

int n,ans;
int a[55];

int main()
{
	cin >> n;
	getchar();
	for (int i = 1;i <= n;i++)
		a[i] = getchar();
	for (int i = 2;i <= n;i++)
		ans += (a[i] == a[i - 1]);
	cout << ans << endl;
	return 0;
}