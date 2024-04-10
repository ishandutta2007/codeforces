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
const int N = 2e3 + 10;
int ask(int c, int d)
{
	cout << "? " << c << ' ' << d << endl;
	int ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a = 0, b = 0;
	int cur = ask(0, 0);
	for (int o = 29; o >= 0; o--)
	{
		int flag = 1;
		int key = ask(1 << o | a, 1 << o | b);
		if (key != cur) flag = 0;
		if (flag)
		{
			if (cur >= 0)
			{
				if (ask(1 << o | a, b) < 0) 
					a |= 1 << o, b |= 1 << o;
			}
			else
			{
				if (ask(a, 1 << o | b) > 0)
					a |= 1 << o, b |= 1 << o;
			}
		}
		else
		{
			if (cur > 0) a |= 1 << o;
			else b |= 1 << o;
			cur = ask(a, b);
		}
	}
	cout << "! " << a << ' ' << b << endl;
	return 0;
}