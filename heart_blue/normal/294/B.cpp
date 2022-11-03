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
int  sum[3][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int k[3] = { 0,0, 0 };
	for (int i = 0; i < n; i++)
	{
		int o, x;
		cin >> o >> x;
		sum[o][++k[o]] = x;
	}
	for (int o = 1; o <= 2; o++)
	{
		sort(sum[o] + 1, sum[o] + k[o] + 1);
		sum[o][0] = 0;
		for (int i = 1; i <= k[o]; i++)
		{
			sum[o][i] += sum[o][i - 1];
		}
	}
	int ans = INF;
	for (int i = 0; i <= k[1]; i++)
	{
		for (int j = 0; j <= k[2]; j++)
		{
			if (sum[1][i] + sum[2][j] <= k[1] - i + (k[2] - j) * 2)
			{
				ans = min(ans, k[1] - i + (k[2] - j) * 2);
			}
		}
	}
	cout << ans << endl;
	return 0;
}