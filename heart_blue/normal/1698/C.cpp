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
		int n;
		scanf("%d", &n);
		vector<int> v;
		map<LL, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
			if (mc[x] <= 3) v.push_back(x);
		}
		int flag = 1;
		for (int i = 0; i < v.size() && flag; i++)
		{
			for (int j = i + 1; j < v.size() && flag; j++)
			{
				for (int k = j + 1; k < v.size() && flag; k++)
				{
					if (!mc.count(v[i] + v[j] + v[k]))
					{
						flag = 0;
					}
				}
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}