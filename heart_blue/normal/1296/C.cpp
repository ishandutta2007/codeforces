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
const int N = 3e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str + 1);
		map<pair<int, int>, int> mc;
		vector<int> v;
		int x = 0;
		int y = 0;
		tuple<int, int, int> ans = make_tuple(int(INF), -1, -1);
		mc[{0, 0}] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (str[i] == 'L') x++;
			if (str[i] == 'R') x--;
			if (str[i] == 'U') y++;
			if (str[i] == 'D') y--;
			if (mc.count(make_pair(x, y)))
				ans = min(ans, make_tuple(i - mc[{x, y}], mc[{x, y}] + 1, i));
			mc[{x, y}] = i;
		}
		int len, l, r;
		tie(len, l, r) = ans;
		if (len == INF) puts("-1");
		else printf("%d %d\n", l, r);
	}
	return 0;
}