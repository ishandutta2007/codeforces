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

long long labs(long long x)
{
	if (x >= 0)
		return x;
	else
		return -x;
}

int main()
{
    long long a, b, xs, ys, xf, yf, xsh, ysh, xfh, yfh;
	
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	cin >> a >> b >> xs >> ys >> xf >> yf;

	xsh = (xs + ys) / (2 * a) - (xs + ys < 0);
	ysh = (xs - ys) / (2 * b) - (xs - ys < 0);
	xfh = (xf + yf) / (2 * a) - (xf + yf < 0);
	yfh = (xf - yf) / (2 * b) - (xf - yf < 0);
	cout << max(labs(xsh - xfh), labs(ysh - yfh)) << endl;

    return 0;
}