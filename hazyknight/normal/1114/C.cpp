#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;

ll n,b,ans = -1;

ll calc(ll v)
{
	ll cur = v,res = 0;
	while (cur <= n)
	{
		res += n / cur;
		if (cur > n / v)
			break;
		cur *= v;
	}
	return res;
}

int main()
{
	cin >> n >> b;
	for (ll i = 2;i * i <= b;i++)
		if (b % i == 0)
		{
			int cnt = 0;
			while (b % i == 0)
			{
				b /= i;
				cnt++;
			}
			if (ans == -1)
				ans = calc(i) / cnt;
			else
				ans = min(ans,calc(i) / cnt);
		}
	if (b != 1)
	{
		if (ans == -1)
			ans = calc(b);
		else
			ans = min(ans,calc(b));
	}
	cout << ans << endl;
	return 0;
}