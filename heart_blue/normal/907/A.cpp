#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
bool check(int x, int y)
{
	return x <= y && 2 * x >= y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = c; i <= 200; i++)
	{
		if (!check(c, i) || !check(d, i)) continue;
		for (int j = max(max(i + 1, 2 * d + 1), b); j <= 200; j++)
		{
			if (!check(b, j)) continue;
			for (int k = max(max(j + 1, 2 * d + 1), a); k <= 200; k++)
			{
				if (!check(a, k)) continue;
				cout << k << ' ' << j << ' ' << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}