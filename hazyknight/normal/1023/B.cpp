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

long long n,k;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if (k > n)
		cout << max(0ll,(n - (k - n) + 1) / 2) << endl;
	else
		cout << max(0ll,((k - 1) - 1 + 1) / 2) << endl;
	return 0;
}