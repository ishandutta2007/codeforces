#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

const long double eps = 1e-6;

int n;

struct Circle
{
	long double x,y,r;
}c1,c2,c3;

pair<long double,long double> rotate(pair<long double,long double> k,long double alpha)
{
	return make_pair(k.first * cos(alpha) - k.second * sin(alpha),k.first * sin(alpha) + k.second * cos(alpha));
}

vector<pair<long double,long double> > cross;

void get_cross(Circle &a,Circle &b)
{
	long double xa = a.x,ya = a.y,ra = a.r;
	long double xb = b.x,yb = b.y,rb = b.r;
	long double L = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	if (L > ra + rb)
		return;
	else if (L < fabs(ra - rb))
		return;
	long double ansx = (ra * ra - rb * rb + L * L) / (2.0000000000 * L);
	long double ansy = sqrt(ra * ra - ansx * ansx);
	long double alpha = atan2(yb - ya,xb - xa);
	pair<long double,long double> ans1 = rotate(make_pair(ansx,ansy),alpha);
	pair<long double,long double> ans2 = rotate(make_pair(ansx,-ansy),alpha);
	ans1.first += xa,ans2.first += xa;
	ans1.second += ya,ans2.second += ya;
	cross.push_back(ans1);
	cross.push_back(ans2);
}

void unique()
{
	for (int i = 0;i + 1 < cross.size();i++)
		for (int j = i + 1;j < cross.size();j++)
			if (fabs(cross[i].first - cross[j].first) < eps && fabs(cross[i].second - cross[j].second) < eps)
			{
				cross.erase(cross.begin() + j);
				j--;
			}
}

int main()
{
	cin >> n;
	if (n == 1)
		cout << 2 << endl;
	else if (n == 2)
	{
		cin >> c1.x >> c1.y >> c1.r;
		cin >> c2.x >> c2.y >> c2.r;
		get_cross(c1,c2);
		unique();
		if (cross.size() <= 1)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
	else
	{
		cin >> c1.x >> c1.y >> c1.r;
		cin >> c2.x >> c2.y >> c2.r;
		cin >> c3.x >> c3.y >> c3.r;
		int size1,size2,size3,size4,size5;
		get_cross(c1,c2);
		unique();
		size1 = cross.size();
		cross.clear();
		get_cross(c1,c3);
		unique();
		size2 = cross.size();
		cross.clear();
		get_cross(c2,c3);
		unique();
		size3 = cross.size();
		cross.clear(); 
		get_cross(c1,c3);
		get_cross(c2,c3);
		unique();
		size4 = cross.size();
		cross.clear();
		get_cross(c1,c2);
		get_cross(c1,c3);
		get_cross(c2,c3);
		unique();
		size5 = cross.size();
		cross.clear();
		if (size1 == 0)
		{
			if (size4 <= 1)
				cout << 4 << endl;
			if (size4 == 2)
			{
				if (size2 == 1)
					cout << 4 << endl;
				else
					cout << 5 << endl;
			}
			if (size4 == 3)
				cout << 5 << endl;
			if (size4 == 4)
				cout << 6 << endl;
		}
		if (size1 == 1)
		{
			if (size4 <= 1)
				cout << 4 << endl;
			else
				cout << 3 + size4 << endl;
		}
		if (size1 == 2)
		{
			if (size4 <= 1)
				cout << 5 << endl;
			else
				cout << 4 + size4 << endl;
		}
	}
	return 0;
}