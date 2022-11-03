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
const int N = 1e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n * n < k)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (k == 0) break;
			if (i == j) a[i][j] = 1, k--;
			else
			{
				if (k >= 2)
				{
					a[i][j] = a[j][i] = 1;
					k -= 2;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}