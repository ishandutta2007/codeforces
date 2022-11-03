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
const int N = 4e4 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		string str;
		scanf("%d%d", &n, &k);
		k = min(k, 25);
		cin >> str;
		map<char, int> mc;
		for (auto& c : str)
		{
			if (!mc.count(c))
			{
				if (k == 0) continue;
				char key = max('a', char(c - k));
				if (!mc.count(key))
				{
					mc[key] = key;
				}
				while (!mc.count(c))
				{
					mc[c--] = mc[key];
					k--;
					if (k == 0) break;
				}
			}
			c = mc[c];
		}
		puts(str.c_str());
	}

	return 0;
}