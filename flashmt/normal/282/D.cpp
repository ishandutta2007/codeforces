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

int g[333][333], d[500], iteration;

int main()
{
	for (int i = 0; i <= 300; i++)
		for (int j = 0; j <= 300; j++)
			{
				++iteration;
				for (int p = 1; p <= i; p++) d[g[i - p][j]] = iteration;
				for (int p = 1; p <= j; p++) d[g[i][j - p]] = iteration;
				for (int p = 1; p <= i && p <= j; p++) d[g[i - p][j - p]] = iteration;
				while (d[g[i][j]] == iteration) g[i][j]++;
			}
			
	int n, x, y, z;
	cin >> n;
	if (n == 1) cin >> x, puts(x ? "BitLGM" : "BitAryo");
	if (n == 2) cin >> x >> y, puts(g[x][y] ? "BitLGM" : "BitAryo");
	if (n == 3) cin >> x >> y >> z, puts(x ^ y ^ z ? "BitLGM" : "BitAryo");
}