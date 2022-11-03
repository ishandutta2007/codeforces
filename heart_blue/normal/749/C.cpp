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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	int cnt1 = 0, cnt2 = 0;
	for (auto &c : str) if (c == 'D') cnt1++; else cnt2++;
	int cnt = 0;
	int p = 0;
	while (1)
	{
		if (cnt1 == 0 || cnt2 == 0) break;
		if (p == n) p = 0;
		if (flag[p])
		{
			p++;
			continue;
		}
		if (cnt == 0)
		{
			if (str[p] == 'D') cnt++;
			else cnt--;
			p++;
			continue;
		}
		if (cnt > 0)
		{
			if (str[p] == 'D') cnt++;
			else cnt--, flag[p] = 1, cnt2--;
		}
		else
		{
			if (str[p] == 'R') cnt--;
			else cnt++, flag[p] = 1, cnt1--;
		}
		p++;
	}
	if (cnt1 == 0) putchar('R');
	else putchar('D');
	return 0;
}