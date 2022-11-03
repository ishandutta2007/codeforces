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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, -1);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int o;
		cin >> o;
		for (int j = 1; j <= o; j++)
		{
			flag[i][j] = 1;
		}
		flag[i][o + 1] = 0;
	}
	for (int j = 1; j <= m; j++)
	{
		int o;
		cin >> o;
		for (int i = 1; i <= o; i++)
		{
			if (flag[i][j] == 0)
			{
				puts("0");
				exit(0);
			}
			flag[i][j] = 1;
		}
		if (flag[o + 1][j] == 1) puts("0"), exit(0);
		flag[o + 1][j] = 0;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (flag[i][j] == -1)
				ans = ans * 2 % INF;
		}
	}
	cout << ans << endl;
	return 0;
}