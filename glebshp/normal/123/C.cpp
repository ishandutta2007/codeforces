#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 250;
const long long inf = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 1;

vector <pair <int, int> > h;
int pr[size], p[size][size], len;
long long could[size][size];
char buf[size];

long long calc_cnt()
{
	int i, j;
	if (buf[0] == ')')
		return 0;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
			could[i][j] = 0;
	could[0][1] = 1;
	for (i = 1; i < len; i++)
	{
		if (buf[i] == ')')
		{
			for (j = 0; j <= i; j++)
				could[i][j] = could[i - 1][j + 1];
			continue;
		}
		if (buf[i] == '(')
		{
			for (j = 1; j <= i + 1; j++)
				could[i][j] = could[i - 1][j - 1];
			continue;
		}
		if (buf[i] == 0)
		{
			could[i][0] = could[i - 1][1];
			could[i][i + 1] = could[i - 1][i];
			for (j = 1; j <= i; j++)
			{
				could[i][j] = could[i - 1][j - 1] + could[i - 1][j + 1];
				if (could[i][j] > inf)
					could[i][j] = inf;
			}
		}
	}
	return could[len - 1][0];
}

int main()
{
	int n, m, i, j;
	long long k, d;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	/*
	freopen("input.txt", "w", stdout);
	cout << 99 << ' ' << 100 << ' ' << 1 << endl;
	for (i = 0; i < 99; i++)
	{
		for (j = 0; j < 100; j++)
			cout << (i + 1) * 100 + j + 1 << ' ';
		cout << endl;
	}
	
	return 0;
	*/
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> p[i][j];
	len = n + m - 1;
	for (i = 0; i < len; i++)
		pr[i] = n * m + 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			pr[i + j] = min(pr[i + j], p[i][j]);
	for (i = 0; i < len; i++)
		h.pb(mp(pr[i], i));
	sort(h.begin(), h.end());
	for (i = 0; i < len; i++)
		buf[i] = 0;
	for (i = 0; i < len; i++)
	{
		buf[h[i].sc] = '(';
		d = calc_cnt();
		if (d < k)
		{
			k -= d;
			buf[h[i].sc] = ')';
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << buf[i + j];
		cout << endl;
	}

    return 0;
}