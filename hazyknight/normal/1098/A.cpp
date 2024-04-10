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

int n;
int p[MAXN];

ll ans;
ll v[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2;i <= n;i++)
		cin >> p[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> v[i];
		if (i != 1 && v[i] != -1)
		{
			if (v[p[i]] == -1)
				v[p[i]] = v[i];
			else
				v[p[i]] = min(v[p[i]],v[i]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		if (v[i] == -1)
			v[i] = v[p[i]];
		if (v[i] < v[p[i]])
		{
			cout << -1 << endl;
			return 0;
		}
		ans += v[i] - v[p[i]];
	}
	cout << ans << endl;
	return 0;
}