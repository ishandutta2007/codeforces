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
const int N = 1e6 + 10;
class Node
{
public:
	int l, r;
	int x, y;
	Node(int l = 0, int r = 0, int x = 0, int y = 0)
	{
		this->l = l;
		this->r = r;
		this->x = x;
		this->y = y;
	}
	bool operator < (const Node& node) const
	{
		if (r != node.r) return r < node.r;
		//if (l != node.l) return l < node.l;
		if (x != node.x) return x < node.x;
		return y < node.y;
	}
};
set<Node> s;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	s.insert(Node(1, n, 1, 1));
	while (q--)
	{
		int x, y;
		char ch[2];
		scanf("%d%d%s", &x, &y, ch);
		auto iter = s.lower_bound(Node(x, x, 0, 0));
		if (iter == s.end())
		{
			puts("0");
			continue;
		}
		int l = iter->l;
		int r = iter->r;
		int ox = iter->x;
		int oy = iter->y;
		if (x < l || x > r)
		{
			puts("0");
			continue;
		}
		s.erase(iter);
		if (ch[0] == 'U')
		{
			printf("%d\n", y - oy + 1);
			if (x - 1 >= l)
			{
				s.insert(Node(l, x - 1, ox, oy));
			}
			if (x + 1 <= r)
			{
				s.insert(Node(x + 1, r, x + 1, oy));
			}
		}
		else
		{
			printf("%d\n", x - ox + 1);
			if (x - 1 >= l)
			{
				s.insert(Node(l, x - 1, ox, y + 1));
			}
			if (x + 1 <= r)
			{
				s.insert(Node(x + 1, r, ox, oy));
			}
		}
	}
	return 0;
}