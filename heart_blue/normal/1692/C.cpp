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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[10];
int b[10];
char str[10][10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int r = -1, c = -1;
		for (int i = 0; i < 8; i++)
		{
			scanf("%s", str[i]);
		}
		for(int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i > 0 && i < 7 && j > 0 && j < 7)
				{
					if (str[i][j] == '#' &&
						str[i - 1][j - 1] == '#' &&
						str[i - 1][j + 1] == '#' &&
						str[i + 1][j - 1] == '#' &&
						str[i + 1][j + 1] == '#')
					{
						r = i + 1, c = j + 1;
					}
				}
			}
		}
		printf("%d %d\n", r, c);
	}
	return 0;
}