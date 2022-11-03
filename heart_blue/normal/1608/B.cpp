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
#include <chrono>
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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		if (a + b > n - 2 || abs(a - b) > 1)
		{
			puts("-1");
			continue;
		}
		vector<int> v;
		int last = INF;
		int l, r;
		if (a >= b)
		{
			v.push_back(0);
			v.push_back(1);
			l = 0, r = 1;
		}
		else
		{
			v.push_back(0);
			v.push_back(-1);
			l = -1, r = 0;
		}
		while (a > 0 || b > 0)
		{
			int x = v[v.size() - 2];
			int y = v[v.size() - 1];
			if (x < y) v.push_back(--l), a--;
			else v.push_back(++r), b--;
		}
		int x = v[v.size() - 2];
		int y = v[v.size() - 1];
		if (x > y)
		{
			while (v.size() < n)
				v.push_back(--l);
		}
		else
		{
			while (v.size() < n)
				v.push_back(++r);
		}
		for (int i = 0; i < v.size(); i++)
		{
			printf("%d%c", -l + v[i] + 1, " \n"[i + 1 == v.size()]);
		}
	}
	return 0;
}