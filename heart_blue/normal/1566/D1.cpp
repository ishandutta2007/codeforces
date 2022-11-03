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
const int N = 3e2 + 10;
int flag[N * N];
int check(int n, int m)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				if (flag[i * m + j] < flag[i * m + k])
					ans++;
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		map<int, vector<int>> mc;
		for (int i = 0; i < n * m; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x].push_back(i);
		}
		int cur = 0;
		for (auto& p : mc)
		{
			auto& v = p.second;
			int ptr = 0;
			while (ptr < v.size())
			{
				int l = cur;
				int r = cur;
				while (ptr < v.size())
				{
					flag[r++] = v[ptr++];
					if (r % m == 0) break;
				}
				reverse(flag + l, flag + r);
				cur = r;
			}
		}
		printf("%d\n", check(n, m));
	}
	return 0;
}