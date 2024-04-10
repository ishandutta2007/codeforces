#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace std;

const int MAXN = 200005;

int n,ans;
int a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i < n;i++)
		ans += a[i + 1] - a[i] - 1;
	cout << ans << endl;
	return 0;
}