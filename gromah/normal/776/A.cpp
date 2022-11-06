#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string a, b, x, y;

int main()
{
	cin >> a >> b;
	cout << a << ' ' << b << endl;
	for (scanf("%d", &n); n; n --)
	{
		cin >> x >> y;
		if (a == x) swap(a, b);
		b = y;
		cout << a << ' ' << b << endl;
	}
	return 0;
}