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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		list<int> l(n);
		for (auto& x : l)
			scanf("%d", &x);
		int o = 1;
		int sum[2] = { 0,0 };
		int pre = 0;
		int tot = 0;
		while (!l.empty())
		{
			tot++;
			o ^= 1;
			int s = 0;
			if (o == 0)
			{
				while (!l.empty() && s <= pre)
				{
					s += l.front();
					l.pop_front();
				}
			}
			else
			{
				while (!l.empty() && s <= pre)
				{
					s += l.back();
					l.pop_back();
				}
			}
			pre = s;
			sum[o] += s;
		}
		printf("%d %d %d\n", tot, sum[0], sum[1]);
	}
	return 0;
}