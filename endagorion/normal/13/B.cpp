#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Point
{
public:
	long long x, y;
};

bool operator == (Point a, Point b)
{
	return (a.x == b.x && a.y == b.y);
}

class Seg
{
public:
	Point A, B;
};

Seg _s(Point a, Point b)
{
	Seg res;
	res.A = a;
	res.B = b;
	return res;
}

long long sm(Seg a, Seg b)
{
	return ((a.B.x - a.A.x) * (b.B.x - b.A.x) + (a.B.y - a.A.y) * (b.B.y - b.A.y));
}

long long vm(Seg a, Seg b)
{
	return ((a.B.x - a.A.x) * (b.B.y - b.A.y) - (a.B.y - a.A.y) * (b.B.x - b.A.x));
}


bool coinc(Seg a, Seg b)
{
	return (a.A == b.A || a.A == b.B || a.B == b.A || a.B == b.B);
}

double dist(Point a, Point b)
{
	return sqrt(1.0*(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long long dist2(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool onSeg(Point a, Point b, Point c)
{
	if (vm(_s(a, b), _s(a, c)) == 0 && sm(_s(a, b), _s(a, c)) < 0) return true;
	else return false;
}

bool good(Point a, Point b, Point c)
{
	return 25*dist2(a, b) >= dist2(b, c) && 25*dist2(a, c) >= dist2(b, c);
}

int main()
{
//	freopen("in", "rt", stdin);
//	freopen("out", "wt", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		Seg a1, a2, a3;
		cin >> a1.A.x >> a1.A.y >> a1.B.x >> a1.B.y;
		cin >> a2.A.x >> a2.A.y >> a2.B.x >> a2.B.y;
		cin >> a3.A.x >> a3.A.y >> a3.B.x >> a3.B.y;		
		if (coinc(a1, a3)) swap(a2, a3);
		if (coinc(a2, a3)) swap(a1, a3);
		if (!coinc(a1, a2))
		{
			cout << "NO\n";
			continue;
		}		
		if (a1.B == a2.B) swap(a1.A, a1.B);
		if (a1.A == a2.B) swap(a2.A, a2.B);
		if (a1.B == a2.A) swap(a1.A, a1.B);
		if (sm(a1, a2) >= 0 && vm(a1, a2) != 0);
		else
		{
			cout << "NO\n";
			continue;
		}
		if (onSeg(a3.A, a2.A, a2.B) && onSeg(a3.B, a1.A, a1.B)) swap(a3.A, a3.B);
		if (!onSeg(a3.A, a1.A, a1.B) || !onSeg(a3.B, a2.A, a2.B))
		{
			cout << "NO\n";
			continue;
		}
		if (good(a3.A, a1.A, a1.B) && good(a3.B, a2.A, a2.B))
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
	return 0;
}