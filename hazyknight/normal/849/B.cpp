#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

struct Line
{
	long long xa,ya,xb,yb;
	Line(long long a,long long b,long long c,long long d)
	{
		xa = a;
		ya = b;
		xb = c;
		yb = d;
	}
	bool check(long long xc,long long yc)
	{
		return (xa - xb) * (yb - yc) == (xb - xc) * (ya - yb);
	}
};

long long n;
long long x[1005];
long long y[1005];

bool calc(long long i1,long long i2)
{
	vector<pair<long long,long long> > v;
	for (long long i = 1;i <= n;i++)
		if (!Line(x[i1],y[i1],x[i2],y[i2]).check(x[i],y[i]))
			v.push_back(make_pair(x[i],y[i]));
	if (!v.size())
		return false;
	if (v.size() == 1)
		return true;
	if ((y[i1] - y[i2]) * (v[0].first - v[1].first) != (v[0].second - v[1].second) * (x[i1] - x[i2]))
		return false;
	for (long long i = 2;i < v.size();i++)
		if (!Line(v[0].first,v[0].second,v[1].first,v[1].second).check(v[i].first,v[i].second))
			return false;
	return true;
}

int main()
{
	cin >> n;
	for (long long i = 1;i <= n;i++)
		cin >> y[i],x[i] = i;
	cout << ((calc(1,2) | calc(2,3) | calc(1,3)) ? "Yes" : "No") << endl;
	return 0;
}