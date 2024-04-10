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
map<string, int> ms;
int a[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void check(const string &str)
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 5)
		{
			if (str[i] != '-')
			{
				return;
			}
		}
		else
		{
			if (!isdigit(str[i]))
			{
				return;
			}
		}
	}
	int d, m, y;
	sscanf(str.c_str(), "%d-%d-%d", &d, &m, &y);
	if (y < 2013 || y > 2015) return;
	if (m < 1 || m > 12) return;
	if (d < 1 || d > a[m]) return;
	ms[str]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 0; i + 10 <= n; i++)
	{
		check(str.substr(i, 10));
	}
	int maxv = 0;
	string ans;
	for (auto &p : ms)
	{
		if (p.second > maxv)
		{
			maxv = p.second;
			ans = p.first;
		}
	}
	cout << ans << endl;
	return 0;
}