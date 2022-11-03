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
const int N = 2e5 + 10;
LL l[N];
LL r[N];
int ans[N];
class Node
{
public:
	LL x, y;
	int pos;
	bool operator < (const Node& node)
	{
		if (y != node.y) return y < node.y;
		if (x != node.x) return x < node.x;
		return pos < node.pos;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(ans, -1);
	vector<Node> vp(n-1);
	set<pair<LL,int>> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	for (int i = 1; i < n; i++)
	{
		vp[i - 1].x = l[i + 1] - r[i];
		vp[i - 1].y = r[i + 1] - l[i];
		vp[i - 1].pos = i;
	}
	for (int i = 1; i <= m; i++)
	{
		LL x;
		cin >> x;
		s.insert({ x,i });
	}
	sort(vp.begin(), vp.end());
	int ptr = 0;
	for (auto &p : vp)
	{
		LL x = p.x;
		LL y = p.y;
		auto iter = s.lower_bound({ x,-1 });
		if (iter != s.end())
		{
			if (iter->first <= y)
			{
				ans[p.pos] = iter->second;
				s.erase(iter);
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (ans[i] == -1)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i < n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}