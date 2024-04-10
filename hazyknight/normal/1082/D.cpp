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

using namespace std;

const int MAXN = 505;

int n,SUM;

pair<int,int> a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].first;
		a[i].second = i;
		SUM += a[i].first;
	}
	if (SUM / 2 < n - 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		if (a[i].first == 1 || i == n)
		{
			cout << "YES" << ' ' << min(n - 1,i) << endl;
			break;
		}
	cout << n - 1 << endl;
	int j = 1;
	for (int i = 2;i <= n;i++)
	{
		if (a[i - 1].first > 0)
		{
			a[i - 1].first--;
			a[i].first--;
			cout << a[i - 1].second << ' ' << a[i].second << endl;
		}
		else
		{
			if (!a[j].first)
				j++;
			a[j].first--;
			a[i].first--;
			cout << a[j].second << ' ' << a[i].second << endl;
		}
	}
	return 0;
}