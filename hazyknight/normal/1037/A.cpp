#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main()
{
	long long n,t = 1,ans = 1;
	cin >> n;
	while (t * 2 - 1 < n)
	{
		t <<= 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}