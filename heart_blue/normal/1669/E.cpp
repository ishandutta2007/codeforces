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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<string, int> mc;
		int n;
		cin >> n;
		while (n--)
		{
			string str;
			cin >> str;
			mc[str]++;
		}
		LL ans = 0;
		for (auto [str, cnt] : mc)
		{
			for (int o = 0; o < 2; o++)
			{
				for (char c = 'a'; c <= 'k'; c++)
				{
					if (str[o] == c) continue;
					string s = str;
					s[o] = c;
					if (mc.count(s))
						ans += 1LL * cnt * mc[s];
				}
			}
		}
		printf("%lld\n", ans / 2);
	}
	return 0;

}