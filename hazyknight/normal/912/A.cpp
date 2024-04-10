#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	long long a,b,x,y,z;
	cin >> a >> b >> x >> y >> z;
	a -= x * 2;
	a -= y;
	b -= y;
	b -= z * 3;
	long long ans = 0;
	if (a < 0)
		ans += a;
	if (b < 0)
		ans += b;
	cout << -ans << endl;
	return 0;
}