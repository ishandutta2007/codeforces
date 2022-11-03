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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int n;
		cin >> n;
		vector<string> vs(n);
		for (auto& s : vs)
			cin >> s;
		int cur = 0;
		int p = 0;
		vector<pair<int, int>> ans;
		while (cur < str.length())
		{
			int maxv = 0;
			int id = -1, pos = -1;
			for (int i = p; i <= cur; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (str.substr(i, vs[j].length()) == vs[j])
					{
						if (i + vs[j].length() > maxv)
						{
							maxv = i + vs[j].length();
							id = j + 1, pos = i + 1;
						}
					}
				}
			}
			if (maxv <= cur) break;
			cur = maxv;
			ans.emplace_back(id, pos);
		}
		if (cur < str.length()) puts("-1");
		else
		{
			printf("%d\n", ans.size());
			for (auto [x, y] : ans)
				printf("%d %d\n", x, y);
		}
	}
	return 0;
}