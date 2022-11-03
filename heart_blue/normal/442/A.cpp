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
int pos[N];
int a[N];
void init()
{
	string c = "RGBYW";
	for (int i = 0; i < c.length(); i++)
	{
		pos[c[i]] = i;
	}
}
int sum(int x)
{
	int ret = 0;
	while (x)
	{
		ret++;
		x -= x&-x;
	}
	return ret;
}
int check(string &str)
{
	return 1 << (pos[str[0]] + 5) | (1 << (str[1] - '1'));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		a[i] = check(str);
	}
	int ans = 10;
	for (int o = 0; o < 1024; o++)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((a[i] != a[j]) && ((a[i] & o) == (a[j] & o)))
				{
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) ans = min(ans, sum(o));
	}
	cout << ans << endl;
	return 0;
}