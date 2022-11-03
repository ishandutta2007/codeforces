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
const int N = 2e2 + 10;
char c[N][N];
int tot[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> (c[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += c[i][j] == '#';
			if (j >= k)
			{
				if (sum == 0)
				{
					for (int o = j; o > j - k; o--) tot[i][o]++;
				}
				sum -= c[i][j - k + 1] == '#';
			}
		}
	}
	for (int j = 1; j <= n; j++)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += c[i][j] == '#';
			if (i >= k)
			{
				if (sum == 0)
				{
					for (int o = i; o > i - k; o--) tot[o][j]++;
				}
				sum -= c[i - k + 1][j] == '#';
			}
		}
	}
	int kx = 1, ky = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tot[i][j] > tot[kx][ky]) kx = i, ky = j;
		}
	}
	cout << kx << ' ' << ky << endl;

	return 0;
}