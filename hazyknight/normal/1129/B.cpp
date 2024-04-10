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
#include <assert.h>
#include <fstream>

using namespace std;

long long k;

int main()
{
	cin >> k;
	for (long long i = 999999;i >= 1;i--)
	{
		long long K = k + i;
		for (long long j = 1999;j >= 3;j -= 2)
			if (K % j == 0 && K / j + (j >> 1) <= i && (i - (j - 1) / 2) * (j - 2) <= K)
			{
				cout << j << endl;
				cout << K / j + (j >> 1) << ' ' << -i - 1 << ' ' << i << ' ';
				for (int l = 1;l < (j >> 1);l++)
					cout << -i - 1 << ' ' << i << ' ';
				cout << endl;
				return 0;
			}
	}
	return 0;
}