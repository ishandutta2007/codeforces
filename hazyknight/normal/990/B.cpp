#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 200005;

int n,K,ans;
int a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> K;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	ans = n;
	int j = 1;
	for (int i = 1;i < n;i++)
	{
		while (j <= n && a[i] == a[j])
			j++;
		if (j <= n && a[i] + K >= a[j])
			ans--;
	}
	cout << ans << endl;
	return 0;
}