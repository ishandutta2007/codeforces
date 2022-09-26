#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace std;

long long a,b,x,y;

int main()
{
	cin >> a >> b >> x >> y;
	long long G = __gcd(x,y);
	x /= G;
	y /= G;
	cout << min(a / x,b / y) << endl;
	return 0;
}