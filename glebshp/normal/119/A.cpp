#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int a, b, n, p = 0;
	cin >> a >> b >> n;
	while (n > 0)
	{
		if (p)
			n -= gcd(n, b);
		else
			n -= gcd(n, a);
		p ^= 1;
	}
	cout << 1 - p << endl;

    return 0;
}