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
const int N = 3e1 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int cnt0, cnt1;
		cin >> cnt0 >> cnt1;
		string str;
		cin >> str;
		int l, r;
		l = 0, r = str.length() - 1;
		int flag = 1;
		while (l < r)
		{
			if (str[l] != str[r])
			{
				if (str[l] == '?') str[l] = str[r];
				else if (str[r] == '?') str[r] = str[l];
				else
				{
					flag = 0;
					break;
				}
			}
			if (str[l] == '0') cnt0 -= 2;
			if (str[l] == '1') cnt1 -= 2;
			l++, r--;
		}
		if (flag == 0)
		{
			puts("-1");
			continue;
		}
		l = 0, r = str.length() - 1;
		while (l < r)
		{
			if (str[l] == '?')
			{
				if (cnt0 > cnt1) str[l] = str[r] = '0', cnt0 -= 2;
				else str[l] = str[r] = '1', cnt1 -= 2;
			}
			l++, r--;
		}
		if (cnt0 < 0 || cnt1 < 0)
		{
			puts("-1");
			continue;
		}
		if (l == r)
		{
			if (str[l] == '0' && cnt1 > 0) flag = 0;
			if (str[r] == '1' && cnt0 > 0) flag = 0;
			if (str[l] == '?')
			{
				if (cnt0) str[l] = '0';
				else str[l] = '1';
			}
		}
		if (flag == 0) puts("-1");
		else puts(str.c_str());
	}
	return 0;
}