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
const int N = 5e1 + 10;
char str[N][N];
void refrain(int& a, int& b)
{
	if (a == -1 || b == -1)
	{
		if (a == -1 && b == -1) a = 0, b = 1;
		if (a == -1) a = b ^ 1;
		else b = a ^ 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int key[2] = { -1,-1 };
		int n, m;
		scanf("%d%d", &n, &m);
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			for (int j = 0; j < m; j++)
			{
				int o = (i + j) & 1;
				if (str[i][j] == 'R')
				{
					if (key[0] == -1) key[0] = o;
					if (key[0] != o) flag = 0;
				}
				if(str[i][j] == 'W')
				{
					if (key[1] == -1) key[1] = o;
					if (key[1] != o) flag = 0;
				}
			}
		}
		refrain(key[0], key[1]);
		if (key[0] == key[1]) flag = 0;
		if (flag == 0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		string res = "00";
		res[key[0]] = 'R';
		res[key[1]] = 'W';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				str[i][j] = res[(i + j) & 1];
			}
			puts(str[i]);
		}
	}
	return 0;
}