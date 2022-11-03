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
		string str;
		cin >> str;
		int p;
		cin >> p;
		map<char, int> mc;
		int tot = 0;
		for (auto& c : str)
		{
			mc[c]++;
			tot += c - 'a' + 1;
		}
		for (auto iter = mc.rbegin(); iter != mc.rend(); iter++)
		{
			while (tot > p && iter->second > 0)
			{
				tot -= iter->first - 'a' + 1;
				iter->second--;
			}
		}
		for (auto& c : str)
		{
			if (mc[c])
				putchar(c), mc[c]--;
		}
		puts("");
	}
	return 0;
}