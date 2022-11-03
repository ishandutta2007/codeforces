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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		int flag = 0;
		cin >> str;
		for (int o = 0; o <= str.length(); o++)
		{
			int pre = -2;
			flag = 1;
			for (int i = 0; i < str.length(); i++)
			{
				if ((i < o && str[i] == '1') || (i >= o && str[i] == '0'))
				{
					if (pre + 1 == i)
					{
						flag = 0;
						break;
					}
					pre = i;
				}
			}
			if (flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}