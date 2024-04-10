#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int BASE = 7340033;

long long f[44][1010];

int main()
{
	f[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		for (int j = 0; j <= 1000; j++) f[i][j] = f[i - 1][j];
		for (int z = 0; z < 3; z++)
			for (int j = 1000; j; j--)
				for (int k = 1; k <= j; k++)
					f[i][j] += f[i][j - k] * f[i - 1][k], f[i][j] %= BASE;
		for (int j = 1000; j; j--) f[i][j] = f[i][j - 1];
		f[i][0] = 1;
	}
	
	int test, n, k;
	cin >> test;
	while (test--)
	{
		cin >> n >> k;
		int h = 0;
		while (n > 2 && n % 2 == 1) n /= 2, h++;
		cout << f[h][k] << endl;
	}
}