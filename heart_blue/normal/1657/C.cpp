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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		int rest = 0;
		int tot = 0;
		string str;
		cin >> str;
		for (int i = 0; i < n; i++)
		{
			if (i + 1 == n)
			{
				rest = 1;
				break;
			}
			if (str[i] == '(') i++, tot++;
			else
			{
				int j = i + 1;
				while (j < n && str[j] != ')')
					j++;
				if (j == n)
				{
					rest = n - i;
					break;
				}
				i = j;
				tot++;

			}
		}
		printf("%d %d\n", tot, rest);
	}
	return 0;
}