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
#include <iomanip>
#include <assert.h>

using namespace std;

const int MAXN = 100005;

int n,id;
int a[MAXN];
int cnt[MAXN];
int st[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] = n - a[i];
		cnt[a[i]]++;
	}
	for (int i = 1;i <= n;i++)
	{
		if (cnt[i] % i != 0)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if (cnt[i])
		{
			st[i] = id + 1;
			id += cnt[i] / i;
		}
	}
	memset(cnt,0,sizeof(cnt));
	cout << "Possible" << endl;
	for (int i = 1;i <= n;i++)
	{
		cout << st[a[i]] << ' ';
		cnt[a[i]]++;
		if (cnt[a[i]] == a[i])
		{
			cnt[a[i]] = 0;
			st[a[i]]++;
		}
	}
	cout << endl;
	return 0;
}