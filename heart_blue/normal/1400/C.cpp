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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		string ans;
		int x;
		cin >> str >> x;
		ans = string(str.length(), '1');
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0')
			{
				if (i - x >= 0) ans[i - x] = '0';
				if (i + x < str.length()) ans[i + x] = '0';
			}
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
			{
				int cnt = 0;
				if (i - x >= 0 && ans[i - x] == '1') cnt = 1;
				if (i + x < str.length() && ans[i + x] == '1') cnt = 1;
				if (cnt == 0)
				{
					ans = "-1";
					break;
				}
			}
		}
		puts(ans.c_str());
	}
	return 0;
}