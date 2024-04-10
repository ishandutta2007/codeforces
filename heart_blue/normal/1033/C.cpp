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
const int N = 1e5 + 10;
int flag[N];
int a[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = n; i > 0; i--)
	{
		int p = pos[i];
		p %= i;
		if (p == 0) p = i;
		while (p <= n)
		{
			if (p != pos[i])
			{
				if (flag[p] == 0 && a[p] > i)
				{
					flag[pos[i]] = 1;
					break;
				}
			}
			p += i;
		}
	}
	for (int i = 1; i <= n; i++) putchar("BA"[flag[i]]);
	return 0;
}