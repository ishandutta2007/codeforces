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

vector <pair <int, int> > good, bad;
vector <int> h;

int main()
{
	bool flag;
	int p1, p2, n, i, c;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> c;
		h.pb(c);
	}

	sort(h.begin(), h.end());
	for (i = 0; i < n; i++)
		if (h[i] % 2)
			if (good.size() != 0 && good.back().fs == h[i])
				good.back().sc += 2;
			else
				good.pb(mp(h[i], 2));
		else
			if (bad.size() != 0 && bad.back().fs == h[i])
				bad.back().sc += 2;
			else
				bad.pb(mp(h[i], 2));
	
	flag = true;
	p1 = 0;
	p2 = 0;
	while (p1 < good.size() && p2 < bad.size())
	{
		if (good[p1].fs < bad[p2].fs)
		{
			if (good[p1].fs + 1 != bad[p2].fs)
			{
				flag = false;
				break;
			}
			bad[p2].sc -= good[p1].sc;
			if (bad[p2].sc == 0 && (p1 < good.size() - 1 || p2 < bad.size() - 1))
			{
				flag = false;
				break;
			}
			if (bad[p2].sc < 0)
			{
				flag = false;
				break;
			}
			p1++;
			if (bad[p2].sc == 0)
				p2++;
		}
		else
		{
			if (bad[p2].fs + 1 != good[p1].fs)
			{
				flag = false;
				break;
			}
			good[p1].sc -= bad[p2].sc;
			if (good[p1].sc == 0 && (p1 < good.size() - 1 || p2 < bad.size() - 1))
			{
				flag = false;
				break;
			}
			if (good[p1].sc < 0)
			{
				flag = false;
				break;
			}
			p2++;
			if (good[p1].sc == 0)
				p1++;
		}
	}
	if (p1 != good.size() || p2 != bad.size())
		flag = false;
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

    return 0;
}