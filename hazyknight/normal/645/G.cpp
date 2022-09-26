#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#include <map>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAXN = 100005;
const ld eps = 1e-7;
const ld PI = acos(-1);

int n;

ld L,u,v,X,Y;
ld arc,itc,agl;
ld x[MAXN];
ld y[MAXN];

vector<pair<ld,ld> > itrsc;

priority_queue<ld,vector<ld>,greater<ld> > Q;

bool check(ld m)
{
	itrsc.clear();
	while (!Q.empty())
		Q.pop();
	u = m / 2;
	v = sqrt(L * L - u * u);
	for (int i = 1;i <= n;i++)
	{
		X = 1;
		Y = y[i] / v;
		if (x[i] != 0)
		{
			Y *= (X = u / x[i]);
			ld r = sqrt(X * X + Y * Y);
			if (r < 1)
				continue;
			arc = acos(1 / r);
		}
		else
			arc = PI / 2;
		agl = ((agl = atan2(Y,X) - arc) < 0 ? agl + 2 * PI : agl);
		itrsc.push_back(make_pair(agl,2 * arc));
	}
	sort(itrsc.begin(),itrsc.end());
	for (int i = 1;i <= 2;i++)
		for (int j = 0;j < itrsc.size();j++)
		{
			X = itrsc[j].first;
			Y = itrsc[j].first + itrsc[j].second;
			while (!Q.empty() && Q.top() < X)
				Q.pop();
			if (!Q.empty() && Q.top() < Y)
				return true;
			Q.push(Y);
			itrsc[j].first += 2 * PI;
		}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> L;
	for (int i = 1;i <= n;i++)
		cin >> x[i] >> y[i];
	ld low = 0,high = 2 * L;
  	while (high - low > eps)
	{
		ld mid = (low + high) / 2;
		if (check(mid))
			high = mid;
		else
			low = mid + eps;
	}
	cout << fixed << setprecision(9) << low << endl;
	return 0;
}