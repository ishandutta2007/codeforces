#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ll a,b,ans,lcm;

void tryit(ll g)
{
	ll upa = ((a - 1) / g + 1) * g,upb = ((b - 1) / g + 1) * g;
	if (upa / g * upb < lcm || (upa / g * upb == lcm && upa - a < ans))
	{
		lcm = upa / g * upb;
		ans = upa - a;
	}
}

int main()
{
	cin >> a >> b;
	if (a == b)
	{
		cout << 0 << endl;
		return 0;
	}
	ans = 9e18,lcm = 9e18;
	ll dif = max(a,b) - min(a,b);
	for (int i = 1;i * i <= dif;i++)
		if (dif % i == 0)
		{
			tryit(i);
			if (i * i != dif)
				tryit(dif / i);
		}
	cout << ans << endl;
	return 0;
}