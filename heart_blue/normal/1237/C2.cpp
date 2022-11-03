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
vector<int> v;
struct Node
{
	int x, y, z;
	int pos;
	void init(int pos)
	{
		this->pos = pos;
		scanf("%d%d%d", &x, &y, &z);
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
	}
	void refrain()
	{
		x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
		y = lower_bound(v.begin(), v.end(), y) - v.begin() + 1;
		z = lower_bound(v.begin(), v.end(), z) - v.begin() + 1;
	}
	bool operator <(const Node& node) const
	{
		if (x != node.x) return x < node.x;
		if (y != node.y) return y < node.y;
		return z < node.z;
	}
};
Node qr[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		qr[i].init(i);
	sort(qr + 1, qr + n + 1);
	sort(v.begin(), v.end());
	/*for (int i = 1; i <= n; i++)
		qr[i].refrain();*/
	vector<Node> vp;
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		if (vp.size())
		{
			if (vp.back().x == qr[i].x && vp.back().y == qr[i].y)
			{
				ans.emplace_back(vp.back().pos, qr[i].pos);
				vp.pop_back();
				continue;
			}
			if (vp.back().x != qr[i].x)
			{
				while (vp.size() > 2)
				{
					if (vp[vp.size() - 2].x == vp[vp.size() - 1].x)
					{
						ans.emplace_back(vp[vp.size() - 2].pos, vp[vp.size() - 1].pos);
						vp.pop_back();
						vp.pop_back();
					}
					else break;
				}
			}
		}
		vp.push_back(qr[i]);
	}
	for (int i = 0; i < vp.size(); i += 2)
	{
		ans.emplace_back(vp[i].pos, vp[i + 1].pos);
	}
	for (auto& p : ans)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}