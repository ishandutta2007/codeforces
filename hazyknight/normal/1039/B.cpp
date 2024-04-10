#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

ll n,k;
ll l,r;

void expend()
{
	l = max(1ll,l - k);
	r = min(n,r + k);
}

bool ask(ll L,ll R)
{
	cout << L << ' ' << R << endl;
	fflush(stdout);
	string ret;
	cin >> ret;
	return ret == "Yes";
}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> n >> k;
	l = 1,r = n;
	while (1)
	{
		if (r - l + 1 <= 45)
		{
			ll pos = l + rand() % (r - l + 1);
			if (ask(pos,pos))
				return 0;
		}
		else
		{
			ll mid = (l + r) >> 1;
			if (ask(l,mid))
				r = mid;
			else
				l = mid + 1;
		}
		expend();
	}
	return 0;
}