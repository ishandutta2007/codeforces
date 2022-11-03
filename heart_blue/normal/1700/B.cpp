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
		int len;
		string s1;
		cin >> len >> s1;
		if (s1[0] != '9')
		{
			for (auto& c : s1)
			{
				c = 9 - (c - '0') + '0';
			}
			puts(s1.c_str());
		}
		else
		{
			string ans(len, '1');
			ans[0] += 10;
			for (int i = len - 1; i >= 0; i--)
			{
				ans[i] -= s1[i] - '0';
				if (ans[i] < '0')
					ans[i] += 10, ans[i - 1]--;
			}
			puts(ans.c_str());
		}
	}
	return 0;
}