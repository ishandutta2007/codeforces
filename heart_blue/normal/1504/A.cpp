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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

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
		int l = 0, r = str.length() - 1;
		int flag = 0;
		while (l <= r)
		{
			if (str[l] == str[r])
			{
				if (str[l] != 'a')
				{
					str.insert(str.begin() + l, 'a');
					flag = 1;
					break;
				}
				l++, r--;
			}
			else
			{
				str.insert(str.begin() + l + 1, 'a');
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			puts("YES");
			puts(str.c_str());
		}
		else
			puts("NO");
	}
	return 0;
}