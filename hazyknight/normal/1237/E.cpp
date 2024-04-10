#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000005;

int n;

int main()
{
	cin >> n;
	if (n == 1 || n == 2)
	{
		puts("1");
		return 0;
	}
	int t = 1;
	while (t < n)
	{
		if (t & 1)
			t = (t + 1) << 1;
		else
			t = t << 1 | 1;
		if (t == n || t + 1 == n)
		{
			puts("1");
			return 0;
		}
	}
	puts("0");
	return 0;
}