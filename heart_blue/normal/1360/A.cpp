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
const int N = 1e3 + 10;
int solve(int a, int b, int c, int d)
{
	return max(max(a, c), b + d);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a[4];
		cin >> a[0] >> a[1];
		a[2] = a[0], a[3] = a[1];
		int res = INF;
		for (int i = 0; i < 2; i++)
		{
			swap(a[0], a[1]);
			for (int j = 0; j < 2; j++)
			{
				swap(a[2], a[3]);
				res = min(res, solve(a[0], a[1], a[2], a[3]));
			}
		}
		printf("%d\n", res * res);
	}
	return 0;
}