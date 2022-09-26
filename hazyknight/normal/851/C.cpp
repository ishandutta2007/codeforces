#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <cmath> 

using namespace std;

struct Vector
{
	int a,b,c,d,e;
	Vector(int a_,int b_,int c_,int d_,int e_)
	{
		a = a_;
		b = b_;
		c = c_;
		d = d_;
		e = e_;
	}
	int operator * (const Vector & p)const
	{
		return a * p.a + b * p.b + c * p.c + d * p.d + e * p.e;
	}
};

struct Point
{
	int a,b,c,d,e;
	Vector operator - (const Point & p)const
	{
		return Vector(p.a - a,p.b - b,p.c - c,p.d - d,p.e - e);
	}
}point[1005];

int n;

vector<int> ans;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> point[i].a >> point[i].b >> point[i].c >> point[i].d >> point[i].e;
	for (int i = 1;i <= n;i++)
	{
		bool ok = true;
		for (int j = 1;j <= n && ok;j++)
			for (int k = 1;k <= n;k++)
				if (i != j && i != k && j != k && (point[i] - point[j]) * (point[i] - point[k]) > 0)
				{
					ok = false;
					break;
				}
		if (ok)
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << endl;
	return 0;
}