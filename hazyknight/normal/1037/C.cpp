#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,ans;

string a,b;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 0;i < n - 1;i++)
		if (a[i] - '0' != a[i + 1] - '0' && a[i] - '0' != b[i] - '0' && b[i] - '0' != b[i + 1] - '0')
		{
			ans++;
			swap(a[i],a[i + 1]);
		}
	for (int i = 0;i < n;i++)
		if (a[i] != b[i])
			ans++;
	cout << ans << endl;
	return 0;
}