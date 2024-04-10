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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n*2; i++)
	{
		for (int j = 0; j < n*2; j++)
		{
			a[i][j] = a[i%n][j%n];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i][n - 1] == 1)
		{
			int x = i, y = n - 1;
			for (int j = 0; j < n - 1; j++)
			{
				if (a[i][j])
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			for (int i = 1; i < n; i++)
			{
				if (a[x + i][y + i])
				{
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}