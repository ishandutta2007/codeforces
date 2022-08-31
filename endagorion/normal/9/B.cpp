#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

const double EPS = 1e-7;

using namespace std;

int n, v1, v2;
double xu, yu;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double f(double x)
{
	return x/v1 + dist(x, 0, xu, yu)/v2;
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	cin >> n >> v1 >> v2;
	vector <double> x(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	cin >> xu >> yu;
	int m = 1;
	for (int i = 2; i < n; ++i)
		if (f(x[i]) < f(x[m]) || (std::abs(f(x[i]) - f(x[m])) < EPS && dist(x[i], 0, xu, yu) < dist(x[m], 0, xu, yu))) m = i;
	cout << m+1 << '\n';
	return 0;
}