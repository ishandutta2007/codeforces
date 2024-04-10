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

const int MAXN = 200005;
const int MOD = 998244353;

int n,ans;
int mark[MAXN];

pair<int,int> a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++)
		if (a[i].first == a[i - 1].first)
		{
			mark[a[i - 1].second + 1]++;
			mark[a[i].second + 1]--;
		}
	int cnt = 0,sum = mark[1];
	for (int i = 2;i <= n;i++)
	{
		sum += mark[i];
		cnt += !sum;
	}
	ans = 1;
	while (cnt--)
		(ans <<= 1) %= MOD;
	cout << ans << endl;
	return 0;
}