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
		int flag = 1;
		string key = str;
		sort(key.begin(), key.end());
		key.resize(unique(key.begin(), key.end()) - key.begin());
		for (auto& c1 : key)
		{
			for (auto& c2 : key)
			{
				if (c2 <= c1) continue;
				char pre = 0;
				for (auto& c : str)
				{
					if (c != c1 && c != c2) continue;
					if (c == pre) flag = 0;
					pre = c;
				}
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}

	return 0;
}