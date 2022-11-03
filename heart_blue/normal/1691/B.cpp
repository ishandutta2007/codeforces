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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, vector<int>> mc;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x].push_back(i);
			a[i] = x;
		}
		int flag = 0;
		for (auto& [x, v] : mc)
		{
			if (v.size() == 1)
				flag = 1;
			v.push_back(v[0]);
			v.erase(v.begin());
			reverse(v.begin(), v.end());
		}
		if (flag)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			int x = a[i];
			a[i] = mc[x].back();
			mc[x].pop_back();
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}