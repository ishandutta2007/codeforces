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

const int MAXN = 105;

int T,n,d;
int a[MAXN];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			if (i > 1)
			{
				int t = min(a[i],d / (i - 1));
				a[1] += t;
				d -= t * (i - 1);
			}
		}
		cout << a[1] << endl;
	}
	return 0;
}