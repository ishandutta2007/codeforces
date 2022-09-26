#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

long long x,y,z;

int main()
{
	cin >> x >> y >> z;
	cout << (x + y) / z << ' ';
	if ((x + y) / z == x / z + y / z)
		cout << 0 << endl;
	else
		cout << min((x + z - 1) / z * z - x,(y + z - 1) / z * z - y) << endl;
	return 0;
}