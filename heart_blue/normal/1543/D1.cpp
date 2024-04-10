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
int add(int x, int y, int b)
{
	int key = 1;
	int ret = 0;
	while (x > 0 || y > 0)
	{
		int c = x % b + y % b;
		c %= b;
		ret += c * key;
		key *= b;
		x /= b, y /= b;
	}
	return ret;
}
int sub(int x, int y, int b)
{
	int key = 1;
	int ret = 0;
	while (x > 0 || y > 0)
	{
		int c = x % b - y % b;
		c %= b;
		if (c < 0) c += b;
		ret += c * key;
		key *= b;
		x /= b, y /= b;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		/*
		0 : 0+x
		1 : 0-x
		2 : 1-0+x
		*/
		int n, k;
		cin >> n >> k;
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			int ret = 0;
			if (i % 2 == 0)
			{
				ret = add(i, cur, k);
				cout << ret << endl;
			}
			else
			{
				ret = sub(cur, i, k);
				cout << ret << endl;
			}
			cur = sub(ret, cur, k);
			int o;
			cin >> o;
			if (o == 1) break;
		}
	}
	return 0;
}