#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main()
{
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a > b)
		swap(a,b);
	if (a > c)
		swap(a,c);
	if (b > c)
		swap(b,c);
	cout << max(0ll,d - (b - a)) + max(0ll,d - (c - b)) << endl;
	return 0;
}