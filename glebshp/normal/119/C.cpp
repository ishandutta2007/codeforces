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

const int size = 110;

struct science
{
	long long a, b, c;
	int rnm;
	science(long long d, long long e, long long f, int g)
	{
		a = d;
		b = e;
		c = f;
		rnm = g;
	}
	science(){}
};

bool operator < (science a, science b)
{
	return a.c < b.c;
}

long long ans[size][size][size];
long long froms[size][size][size], fromf[size][size][size];
int n, m;
vector <pair <long long, long long> > ansv;
vector <science> sc;
long long k;

void trytomove(int sf, int ss, int day, long long wt)
{
	if (wt - k >= sc[sf].a && wt - k <= sc[sf].b && ans[sf][day - 1][wt - k - sc[sf].a] != -1)
	{
		if (ans[sf][day - 1][wt - k - sc[sf].a] + wt > ans[ss][day][wt - sc[ss].a])
		{
			ans[ss][day][wt - sc[ss].a] = ans[sf][day - 1][wt - k - sc[sf].a] + wt;
			fromf[ss][day][wt - sc[ss].a] = sf;
			froms[ss][day][wt - sc[ss].a] = wt - k - sc[sf].a;
		}
	}
	if (wt % k == 0 && wt / k >= sc[sf].a && wt / k <= sc[sf].b && ans[sf][day - 1][wt / k - sc[sf].a] != -1)
	{
		if (ans[sf][day - 1][wt / k - sc[sf].a] + wt > ans[ss][day][wt - sc[ss].a])
		{
			ans[ss][day][wt - sc[ss].a] = ans[sf][day - 1][wt / k - sc[sf].a] + wt;
			fromf[ss][day][wt - sc[ss].a] = sf;
			froms[ss][day][wt - sc[ss].a] = wt / k - sc[sf].a;
		}
	}
}

int main()
{
	int i, j, q, h;
	long long pi, pj, npi, npj, mx, a, b, c;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		sc.pb(science(a, b, c, i));
	}

	sort(sc.begin(), sc.end());
	for (i = 0; i < m; i++)
	{
		for (j = 0; j <= sc[i].b - sc[i].a; j++)
		{
			ans[i][0][j] = sc[i].a + j;
			fromf[i][0][j] = -1;
			froms[i][0][j] = -1;
		}
		for (j = 1; j < n; j++)
		{
			for (q = 0; q <= sc[i].b - sc[i].a; q++)
			{
				ans[i][j][q] = -1;
				fromf[i][j][q] = -1;
				froms[i][j][q] = -1;
				for (h = 0; h < i; h++)
					if (sc[h].c < sc[i].c)
						trytomove(h, i, j, q + sc[i].a);
			}
		}
	}
	mx = -1;
	pi = -1;
	pj = -1;
	for (i = 0; i < m; i++)
		for (j = 0; j <= sc[i].b - sc[i].a; j++)
			if (ans[i][n - 1][j] > mx)
			{
				mx = ans[i][n - 1][j];
				pi = i;
				pj = j;
			}
	if (pi == -1)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		ansv.clear();
		for (i = 0; i < n; i++)
		{
			ansv.pb(mp(sc[pi].rnm + 1, pj + sc[pi].a));
			npi = fromf[pi][n - i - 1][pj];
			npj = froms[pi][n - i - 1][pj];
			pi = npi, pj = npj;
		}
		for (i = n - 1; i >= 0; i--)
			cout << ansv[i].fs << ' ' << ansv[i].sc << endl;
	}

    return 0;
}