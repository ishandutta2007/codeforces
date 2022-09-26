#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int x,y,z,a,b,c;

int main()
{
	cin >> x >> y >> z >> a >> b >> c;
	if (a < x)
	{
		cout << "NO" << endl;
		return 0;
	}
	a -= x;
	if (a + b < y)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (a + b - y + c < z)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}