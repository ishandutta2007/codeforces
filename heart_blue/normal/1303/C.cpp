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
		map<char, int> mc;
		string str;
		cin >> str;
		string ans = string(1, str[0]);
		int ptr = 0;
		mc[str[0]] = 0;
		int flag = 1;
		for (int i = 1; i < str.length(); i++)
		{
			if (mc.count(str[i]))
			{
				if (abs(mc[str[i]] - ptr) != 1)
				{
					flag = 0;
					break;
				}
				ptr = mc[str[i]];
			}
			else
			{
				if (ptr == 0) ans = str[i] + ans, ptr = 0;
				else if (ptr == ans.length() - 1)
				{
					ans.push_back(str[i]);
					ptr = ans.length() - 1;
				}
				else
				{
					flag = 0;
					break;
				}
				for (int i = 0; i < ans.length(); i++)
					mc[ans[i]] = i;
			}
		}
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (!mc.count(i))
				ans.push_back(i);
		}
		if (flag) puts("YES"), puts(ans.c_str());
		else puts("NO");
	}
	return 0;
}