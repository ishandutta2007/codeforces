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
const int N = 2e5 + 10;
int flag[N][10][10];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str + 1);
		string ans;
		for (int i = '0'; i <= '9'; i++)
		{
			for (int j = i; j <= '9'; j++)
			{
				if (!ans.empty() && ans != "-") continue;
				int c1 = i, c2 = j;
				ans.clear();
				for (int k = 1; k <= n; k++)
				{
					char c = str[k];
					if (c >= c2) ans.push_back('2'), c2 = c;
					else if (c >= c1 && c <= j) ans.push_back('1'), c1 = c;
					else
					{
						ans = "-";
						break;
					}
				}
			}
		}
		puts(ans.c_str());
	}
	return 0;
}