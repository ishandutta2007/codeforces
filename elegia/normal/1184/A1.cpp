#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

long long r;

int main()
{
	cin >> r;
	for (long long x = 1;x * x + 3 * x + 1 <= r;x++)
		if ((r - x * x - x - 1) % (2 * x) == 0)
		{
			cout << x << ' ' << (r - x * x - x - 1) / (2 * x) << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}