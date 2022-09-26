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

ll l[MAXN];

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> l[i];
	cin >> s;
	bool haveW = 0;
	ll sumG = 0,energy = 0,ans = 0;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == 'L')
		{
			if (energy < l[i])
			{
				ans += (haveW ? 3 : 5) * (l[i] - energy);
				energy = l[i];
			}
			ans += l[i];
			energy -= l[i];
		}
		if (s[i] == 'W')
		{
			ans += 3 * l[i];
			energy += l[i];
			haveW = true;
		}
		if (s[i] == 'G')
		{
			ans += 5 * l[i];
			sumG += 2 * l[i];
			energy += l[i];
		}
		sumG = min(sumG,energy);
	}
	if (energy > 0)
	{
		if (energy <= sumG)
			ans -= energy * 2;
		else
		{
			ans -= sumG * 2;
			energy -= sumG;
			ans -= energy;
		}
	}
	cout << ans << endl;
	return 0;
}