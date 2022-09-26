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
#include <iomanip>

#define x first
#define y second

using namespace std;

typedef long long ll;

ll q,n,m;

pair<ll,ll> c[4];

ll calcB(ll xa,ll ya,ll xb,ll yb)
{
	if (((xb - xa + 1) * (yb - ya + 1)) & 1)
		return (((xb - xa + 1) * (yb - ya + 1)) >> 1) + ((xa + ya) & 1);
	return (((xb - xa + 1) * (yb - ya + 1)) >> 1);
}

ll calcW(ll xa,ll ya,ll xb,ll yb)
{
	if (((xb - xa + 1) * (yb - ya + 1)) & 1)
		return (((xb - xa + 1) * (yb - ya + 1)) >> 1) + (~(xa + ya) & 1);
	return (((xb - xa + 1) * (yb - ya + 1)) >> 1);
}

bool cmp1(pair<ll,ll> a,pair<ll,ll> b)
{
	return a.x < b.x;
}

bool cmp2(pair<ll,ll> a,pair<ll,ll> b)
{
	return a.y < b.y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> q;
	while (q--)
	{
		cin >> m >> n;
		for (int i = 0;i < 4;i++)
			cin >> c[i].x >> c[i].y;
		ll black = calcB(1,1,n,m);
		black -= calcB(c[0].x,c[0].y,c[1].x,c[1].y);
		black += calcW(c[2].x,c[2].y,c[3].x,c[3].y);
		if (c[1].x >= c[2].x && c[0].x <= c[3].x && c[1].y >= c[2].y && c[0].y <= c[3].y)
		{
			sort(c,c + 4,cmp1);
			int xa = c[1].x,xb = c[2].x;
			sort(c,c + 4,cmp2);
			int ya = c[1].y,yb = c[2].y;
			black += calcB(xa,ya,xb,yb);
		}
		cout << n * m - black << ' ' << black << endl;
	}
	return 0;
}