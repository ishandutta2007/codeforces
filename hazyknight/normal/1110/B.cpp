#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 100005;

int n,m,k,ans;
int a[MAXN];
int b[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	for (int i = 1;i < n;i++)
	{
		a[i] = b[i + 1] - b[i] - 1;
		ans += b[i + 1] - b[i];
	}
	ans++;
	sort(a + 1,a + n);
	k--;
	for (int i = n - 1;i >= 1 && k;i--,k--)
		ans -= a[i];
	cout << ans << endl;
	return 0;
}