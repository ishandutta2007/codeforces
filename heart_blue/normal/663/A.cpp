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
	string str;
	getline(cin, str);
	int pos = 1;
	int neg = 0;
	int n = 0;
	for (auto &c : str)
	{
		if (c == '+') pos++;
		else if (c == '-') neg++;
		else if (isdigit(c)) n = n * 10 + c - '0';
	}
	if (pos - neg * n > n || pos * n - neg < n)
	{
		puts("Impossible");
		return 0;
	}
	int tot = pos*n - neg*n;
	int sign = 1;
	puts("Possible");
	for (auto &c : str)
	{
		if (c != '?')
		{
			putchar(c);
			if (c == '+') sign = 1;
			else if(c == '-') sign = -1;
		}
		else
		{
			if (sign == -1)
			{
				int o = 0;
				if (tot <= n)
				{
					o = min(n - 1, n - tot);
					tot += o;
				}
				printf("%d", n-o);
			}
			else
			{
				int o = 0;
				if (tot >= n)
				{
					o = min(n - 1, tot - n);
					tot -= o;
				}
				printf("%d", n - o);
			}
		}
	}
	return 0;
}