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

int T,n;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n == 1)
			puts("-1");
		else
		{
			for (int i = 1;i < n;i++)
				putchar('3');
			putchar('4');
			putchar('\n');
		}
	}
	return 0;
}