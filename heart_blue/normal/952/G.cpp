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
const int N = 5000 + 10;
char a[N][N] =
{
	".......X.......",
	"......XXX......",
	".....XXXXX.....",
	"....XXXXXXX....",
	"...XXXXXXXXX...",
	"..XXXXXXXXXXX..",
	".XXXXXXXXXXXXX.",
	"..............."
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 'X') continue;
			a[i][j] = '.';
		}
	}*/
	MEM(a, '.');
	string ans = "";
	int cur = 0;
	string str;
	cin >> str;
	for (auto &c : str)
	{
		if (cur <= c) cur += 256;
		ans += string(cur - c - 1, '-');
		ans.push_back('.');
		cur = c;
	}
	int n = 1000;
	int k = 0;
	for (int i = 0; i < n; i += 3)
	{
		for (int j = 0; j + 2 < n; j += 3)
		{
			if (k == ans.length()) break;
			if (ans[k] == '[')
			{
				a[i][j + 1] = 'X';
				a[i + 1][j] = 'X';
				a[i + 1][j + 1] = 'X';
			}
			else if (ans[k] == ']')
			{
				a[i][j + 1] = 'X';
				a[i + 1][j + 1] = 'X';
				a[i + 1][j + 2] = 'X';
			}
			else if (ans[k] == '+')
			{
				a[i][j + 1] = 'X';
				a[i + 1][j] = 'X';
				a[i + 1][j + 1] = 'X';
				a[i + 1][j + 2] = 'X';
			}
			else if (ans[k] == '-')
			{
				a[i + 1][j + 1] = 'X';
			}
			else if (ans[k] == '.')
			{
				a[i+1][j + 1] = 'X';
				a[i + 2][j + 1] = 'X';
				k++;
				break;
			}
			k++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			putchar(a[i][j]);
		}
		puts("");
	}
	return 0;
}