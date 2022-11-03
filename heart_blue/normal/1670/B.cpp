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
		int n;
		scanf("%d", &n);
		scanf("%s", str);
		int m;
		scanf("%d", &m);
		map<char, int> mc;
		while (m--)
		{
			char c;
			scanf(" %c", &c);
			mc[c]++;
		}
		int cur = 0;
		int pre = 0;
		for (int i = 1; i < n; i++)
		{
			if (mc[str[i]])
			{
				cur = max(i - pre, cur);
				pre = i;
			}
		}
		printf("%d\n", cur);
	}

	return 0;
}