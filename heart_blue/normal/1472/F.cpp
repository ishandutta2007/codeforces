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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL ans[N];
LL sum[N];
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
		map<int, int> mc;
		while (m--)
		{
			int r, c;
			scanf("%d%d", &r, &c);
			mc[c] |= 1 << (r - 1);
		}
		vector<pair<int, int>> vp;
		for (auto p : mc)
			vp.push_back(p);
		int flag = 1;
		for (int i = 0; i < vp.size(); i++)
		{
			if (vp[i].second == 3) continue;
			if (i + 1 == vp.size())
			{
				flag = 0;
				break;
			}
			if (vp[i + 1].second == 3)
			{
				flag = 0;
				break;
			}
			auto [pos1, o1] = vp[i];
			auto [pos2, o2] = vp[i + 1];
			if ((pos2 - pos1) % 2 == 1 && o1 != o2) flag = 0;
			if ((pos2 - pos1) % 2 == 0 && o1 == o2) flag = 0;
			if (flag == 0) break;
			i++;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}