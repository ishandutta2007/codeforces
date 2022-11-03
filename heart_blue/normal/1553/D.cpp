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
const int N = 2e2 + 10;
vector<int> v[N][2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		for (int i = 0; i < N; i++)
		{
			for (int o = 0; o < 2; o++)
			{
				v[i][o].clear();
			}
		}
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++)
		{
			v[s1[i]][i & 1].push_back(i);
		}
		int flag = 0;
		for (int o = 0; o < 2; o++)
		{
			int cur = -1;
			flag = 1;
			int x = o;
			for (auto& c : s2)
			{
				auto iter = upper_bound(v[c][x].begin(), v[c][x].end(), cur);
				if (iter == v[c][x].end())
				{
					flag = 0;
					break;
				}
				x ^= 1;
				cur = *iter;
			}
			if ((s1.length() - cur) % 2 == 0) flag = 0;
			if (flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}