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

typedef long long ll;

const int MAXN = 100005;

int n,m;
int r[MAXN];
int pos[MAXN];

pair<int,int> a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> r[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		pos[a[i].second] = i;
	int cur = 1;
	for (int t,d,i = 1;i <= m;i++)
	{
		cin >> t >> d;
		int T = pos[t];
		if (d <= r[t])
		{
			r[t] -= d;
			cout << (ll)a[T].first * d << endl;
			continue;
		}
		ll sum = (ll)r[t] * a[T].first;
		d -= r[t];
		r[t] = 0;
		while (cur <= n && d > 0)
		{
			if (r[a[cur].second] <= d)
			{
				sum += (ll)r[a[cur].second] * a[cur].first;
				d -= r[a[cur].second];
				r[a[cur].second] = 0;
				cur++;
			}
			else
			{
				sum += (ll)d * a[cur].first;
				r[a[cur].second] -= d;
				d = 0;
			}
		}
		if (d)
			cout << 0 << endl;
		else
			cout << sum << endl;
	}
	return 0;
}