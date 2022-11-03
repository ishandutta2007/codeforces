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
const int N = 2e6 + 10;
char str[N];
int cnt[N];
bool check(int a1, int a2, int a3, int a4, int a[])
{
	int c[10];
	MEM(c, 0);
	c[4] = a1;
	c[7] = a2;
	for (int i = 0; i <= a3 + a4; i++) str[i] = a[i & 1] + '0', c[a[i & 1]]--;
	if (c[4] < 0 || c[7] < 0)
	{
		return false;
	}
	for (int i = 0; i <= a3 + a4; i++)
	{
		if (str[i] == '4')
		{
			cnt[i] = c[4];
			break;
		}
	}
	for (int i = a3 + a4; i >= 0; i--)
	{
		if (str[i] == '7')
		{
			cnt[i] = c[7];
			break;
		}
	}
	for (int i = 0; i <= a3 + a4; i++)
	{
		cnt[i]++;
		while (cnt[i]--) putchar(str[i]);
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	if (abs(a3 - a4) > 1)
	{
		puts("-1");
		return 0;
	}
	int a[2] = { 4,7 };
	if (a3 >= a4 && check(a1, a2, a3, a4, a)) return 0;
	swap(a[0], a[1]);
	if (a3 <= a4 && check(a1, a2, a3, a4, a)) return 0;
	puts("-1");
	return 0;
}