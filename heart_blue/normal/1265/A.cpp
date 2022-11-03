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
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int flag = 1;
		for (int i = 1; str[i]; i++)
		{
			if (str[i] != '?')
			{
				if (str[i] == str[i - 1]) flag = 0;
			}
			else
			{
				for (int o = 'a'; o <= 'c'; o++)
				{
					if (o == str[i - 1] || o == str[i + 1]) continue;
					str[i] = o;
					break;
				}
			}
		}
		if (flag) puts(str + 1);
		else puts("-1");
	}
	return 0;
}