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

typedef long long ll;

const int MAXN = 55;

ll s,x;
ll f[MAXN][2];

int main()
{
	cin >> s >> x;
	f[0][0] = 1;
	for (int i = 1;i <= 50;i++)
	{
		ll bs = (s >> (i - 1) & 1),bx = (x >> (i - 1) & 1);
		for (int j = 0;j < 2;j++)
			for (int k = 0;k < 2;k++)
				for (int l = 0;l < 2;l++)
					if ((k ^ l) == bx && ((j + k + l) & 1) == bs)
						f[i][j + k + l >= 2] += f[i - 1][j];
	}
	printf("%lld\n",f[50][0] - (s == x) * 2);
	return 0;
}