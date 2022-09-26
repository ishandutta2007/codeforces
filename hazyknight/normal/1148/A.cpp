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
	long long a,b,c,ans = 0;
	cin >> a >> b >> c;
	ans = 2 * c;
	if (a < b)
		swap(a,b);
	if (a == b)
		ans += a + b;
	else
		ans += b + 1 + b;
	cout << ans << endl;
	return 0;
}