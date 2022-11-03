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
		vector<string> vs = { "25","00","50","75" };
		string str;
		cin >> str;
		int ans = INF;
		int len = str.length();
		for (auto& s : vs)
		{
			for (int i = 0; i < len; i++)
			{
				if (str[i] != s[0]) continue;
				for (int j = i + 1; j < len; j++)
				{
					if (str[j] != s[1]) continue;
					ans = min(ans, len - i - 2);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}