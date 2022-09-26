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

ll n,dx,dy;
ll xa,ya,xb,yb;

string s;

bool ok(ll len)
{
	ll X = xa,Y = ya;
	for (int i = 0;i < len % n;i++)
	{
		if (s[i] == 'U')
			Y++;
		if (s[i] == 'D')
			Y--;
		if (s[i] == 'L')
			X--;
		if (s[i] == 'R')
			X++;
	}
	X += dx * (len / n);
	Y += dy * (len / n);
	return abs(X - xb) + abs(Y - yb) <= len;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output2.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin >> xa >> ya >> xb >> yb >> n >> s;
	if (xa == xb && ya == yb)
	{
		cout << 0 << endl;
		return 0;
	}
	ll X = xa,Y = ya;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == 'U')
			Y++;
		if (s[i] == 'D')
			Y--;
		if (s[i] == 'L')
			X--;
		if (s[i] == 'R')
			X++;
	}
	dx = X - xa,dy = Y - ya;
	if (!ok(1e18))
	{
		cout << -1 << endl;
		return 0;
	}
	ll low = 0,high = 1e18;
	while (low < high)
	{
		ll mid = (low + high) >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	cout << low << endl;
	return 0;
}