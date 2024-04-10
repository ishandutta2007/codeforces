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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 20;
char chess[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 8;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> chess[i][j];
		}
	}
	int ans1 = 8;
	int ans2 = 8;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (isalpha(chess[i][j]))
			{
				if (chess[i][j] == 'W')
				{
					ans1 = min(ans1, i);
				}
				break;
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (isalpha(chess[i][j]))
			{
				if (chess[i][j] == 'B')
				{
					ans2 = min(ans2, n - i - 1);
				}
				break;
			}
		}
	}
	if (ans1 <= ans2) puts("A");
	else puts("B");
	return 0;
}