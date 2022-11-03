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
LL multy(LL x, LL y)
{
	if (x > 4 * INF * INF / y) return 4 * INF * INF;
	else return x * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int flag = 1;
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i])
			{
				int ok = 0;
				for (int j = i + 1; j < n; j++)
				{
					if (s2[j] == s2[i])
					{
						ans.emplace_back(i, j);
						swap(s1[i], s2[j]);
						ok = 1;
						break;
					}
					if (s1[j] == s1[i])
					{
						ans.emplace_back(j, i);
						swap(s1[j], s2[i]);
						ok = 1;
						break;
					}
				}
				if (ok) continue;
				ans.emplace_back(i, i);
				swap(s1[i], s2[i]);
				for (int j = i + 1; j < n; j++)
				{
					if (s2[j] == s2[i])
					{
						ans.emplace_back(i, j);
						swap(s1[i], s2[j]);
						ok = 1;
						break;
					}
					if (s1[j] == s1[i])
					{
						ans.emplace_back(j, i);
						swap(s1[j], s2[i]);
						ok = 1;
						break;
					}
				}
				if (!ok) flag = 0;
				if (flag == 0) break;
			}
		}
		if (flag)
		{
			puts("Yes");
			printf("%d\n", ans.size());
			for (auto& p : ans)
				printf("%d %d\n", p.first + 1, p.second + 1);
		}
		else puts("No");
	}
	return 0;
}