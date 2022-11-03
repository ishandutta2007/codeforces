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
const int N = 3e2 + 10;
char a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 9;
	MEM(a, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) cin >> a[i][j];
	}
	int x, y;
	cin >> x >> y;
	x--, y--;
	int ox = x % 3;
	int oy = y % 3;
	int flag = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[ox*3+i][oy*3+j] == '.')
			{
				a[ox * 3 + i][oy * 3 + j] = '!';
				flag = 1;
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (a[i][j] == '.') a[i][j] = '!';
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i > 0 && i % 3 == 0) puts("");
		for (int j = 0; j < 9; j++)
		{
			if (j > 0 && j % 3 == 0) putchar(' ');
			putchar(a[i][j]);
		}
		puts("");
	}
	return 0;
}