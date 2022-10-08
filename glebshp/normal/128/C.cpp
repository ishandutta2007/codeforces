#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const long long mdl = 1000 * 1000 * 1000 + 7;

const int size = 1000 + 2;

long long ways[size][size];

int main()
{
	int n, m, k, i, j, lm, h;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	lm = max(n, m);
	for (i = 1; i <= lm; i++)
		ways[0][i] = 1;
	for (h = 1; h <= k; h++)
	{
		long long sum = 0;
		long long ans = 0;
		for (i = 1; i <= lm; i++)
		{
			ways[h][i] = ans;
			sum = (sum + ways[h - 1][i - 1]) % mdl;
			ans = (ans + sum) % mdl;
			//for (j = 1; j <= i - 2; j++)
			///	ways[h][i] = (ways[h][i] + ways[h - 1][j] * (i - 1 - j)) % mdl;
		}
	}

	cout << (ways[k][n] * ways[k][m]) % mdl;

    return 0;
}