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
const int N = 4e4 + 10;
bool contain(int l, int r, int x)
{
	return x >= l && x <= r;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int w, h, n;
	cin >> w >> h >> n;
	vector<tuple<int, int, int, int>> vp, key;
	vp.emplace_back(0, w, 0, h);
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		key.emplace_back(x1, y1, x2, y2);
	}
	while (!key.empty())
	{
		for (int o = 0; o < key.size(); o++)
		{
			auto [x1, y1, x2, y2] = key[o];
			int flag = -1;
			int len = (x2 - x1) + (y2 - y1);
			for (int i = 0; i < vp.size(); i++)
			{
				auto [lx, rx, ly, ry] = vp[i];
				
				if (contain(lx, rx, x1) &&
					contain(lx, rx, x2) &&
					contain(ly, ry, y1) &&
					contain(ly, ry, y2))
				{
					if (x1 == x2)
					{
						if (ry - ly != len) continue;
						flag = i;
						vp.emplace_back(lx, x1, ly, ry);
						vp.emplace_back(x1, rx, ly, ry);
					}
					else
					{
						if (rx - lx != len) continue;
						flag = i;
						vp.emplace_back(lx, rx, ly, y1);
						vp.emplace_back(lx, rx, y1, ry);
					}
					vp.erase(vp.begin() + i);
					break;
				}
			}
			if (flag != -1)
			{
				key.erase(key.begin() + o);
				break;
			}
		}
	}
	vector<int> ans;
	for (auto [l1, r1, l2, r2] : vp)
	{
		ans.push_back((r2 - l2) * (r1 - l1));
	}
	sort(ans.begin(), ans.end());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}