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

int n,k,ans;

int main()
{
	cin >> n >> k;
	k = min(k,n - k + 1);
	ans = 4;
	n--;
	ans += 3 * (k - 1) - 1;
	if (n - k + 1 > 0)
	{
		ans += k;
		ans += 3 * (n - k + 1) - 1;
	}
	cout << ans << endl;
	return 0;
}