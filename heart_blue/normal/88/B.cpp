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
const int N = 3e1 + 10;
char str[N][N];
int flag[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	d *= d;
	MEM(flag, -1);
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'S')
				s = 1;
			else
				flag[str[i][j]] = 1;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
		if (s && flag[i] == 1) flag[toupper(i)] = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] != 'S') continue;
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < m; y++)
				{
					int dx = x - i;
					int dy = y - j;
					if (islower(str[x][y]) && dx * dx + dy * dy <= d)
					{
						flag[toupper(str[x][y])] = 1;
					}
				}
			}
		}
	}
	int len;
	cin >> len;
	string ss;
	cin >> ss;
	int ans = 0;
	for (auto& c : ss)
	{
		if (flag[c] == -1) puts("-1"), exit(0);
		ans += flag[c] - 1;
	}
	cout << ans << endl;
	return 0;
}