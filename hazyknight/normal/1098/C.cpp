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

ll n,s,id;
ll c[MAXN];
ll st[MAXN];
ll ch[MAXN];

void solve(int bc)
{
	ll tmp = n,lev = 0;
	for (ll i = 1;tmp;i++)
	{
		lev = i;
		ll lim = min(tmp,(i == 1 ? 1 : c[i - 1] * bc));
		for (ll j = 1;j <= lim;j++)
		{
			ll remain = tmp - j - 1;
			if (j == lim || remain * (i + 1) + remain * (remain + 1) / 2 < s - i * (j + 1))
			{
				c[i] = j;
				tmp -= j;
				s -= j * i;
				break;
			}
		}
	}
	int ST = lev;
	for (int i = 2;i <= lev;i++)
		if (c[i] <= (c[i - 1] - 1) * bc)
		{
			ST = i - 1;
			break;
		}
	while (s)
	{
		int minus = min(s,lev - ST);
		s -= minus;
		c[ST]--;
		c[ST + minus]++;
		while (c[ST] <= (c[ST - 1] - 1) * bc)
			ST--;
	}
	st[1] = 1;
	id = 2;
	for (int i = 2;i <= lev;i++)
	{
		st[i] = id;
		for (int j = 1;j <= c[i];j++,id++)
		{
			cout << st[i - 1] << ' ';
			ch[i - 1]++;
			if (ch[i - 1] == bc)
			{
				st[i - 1]++;
				ch[i - 1] = 0;
			}
		}
	}
	cout << endl;
}

int main()
{
	cin >> n >> s;
	if (n * (n + 1) / 2 < s || 2 * n - 1 > s)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (ll i = 1;i < n;i++)
	{
		ll sum = 0,cnt = 1,tmp = n;
		for (ll j = 1;tmp;j++)
		{
			sum += min(cnt,tmp) * j;
			tmp -= min(cnt,tmp);
			cnt *= i;
		}
		if (sum > s)
			continue;
		solve(i);
		return 0;
	}
	return 0;
}