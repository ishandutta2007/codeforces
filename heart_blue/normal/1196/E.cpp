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
const int N = 2e5 + 10;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int b, w;
		scanf("%d%d", &b, &w);
		if (min(b, w) * 3 + 1 < max(b, w))
		{
			puts("NO");
			continue;
		}
		int x = 2;
		int y = x;
		if (b < w) y++, swap(b, w);
		vector<pair<int, int>> vp;
		for (int i = 0; i < w; i++)
		{
			vp.emplace_back(x, y + (i * 2));
			vp.emplace_back(x, y + (i * 2 + 1));
		}
		for (int i = 0; i < w && vp.size() < w + b; i++)
		{
			for (int o = 0; o < 2 && vp.size() < w + b; o++)
			{
				vp.emplace_back(x + dx[o], y + (i * 2) + dy[o]);
			}
		}
		vp.emplace_back(x, y - 1);
		while (vp.size() > w + b) vp.pop_back();
		puts("YES");
		for (auto& p : vp)
			printf("%d %d\n", p.first, p.second);
	}
	return 0;
}