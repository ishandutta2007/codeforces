#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

int n,MAX,ans;
int a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		MAX = max(MAX,a[i]);
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++,ans = max(ans,cnt))
		if (a[i] == MAX)
			cnt++;
		else
			cnt = 0;
	cout << ans << endl;
	return 0;
}