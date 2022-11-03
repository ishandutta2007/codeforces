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
class UnionFind
{
private:
	int p[N];
public:
	int size(int x)
	{
		int px = Find(x);
		return -p[px];
	}
	void init()
	{
		MEM(p, -1);
	}
	int Find(int x)
	{
		int root = x;
		while (p[root] >= 0) root = p[root];
		while (x != root)
		{
			int tmp = p[x];
			p[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (size(px) > size(py)) swap(px, py);
		int total = size(px) + size(py);
		p[px] = py;
		p[py] = -total;
	}
} uf;
map<string, int> ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		ms[str] = i;
	}
	while (m--)
	{
		int o;
		string s1, s2;
		cin >> o >> s1 >> s2;
		int x = ms[s1], y = ms[s2];
		if (o == 1)
		{
			if (uf.Find(x) == uf.Find(y + n)) puts("NO");
			else
			{
				puts("YES");
				if (uf.Find(x) != uf.Find(y))
				{
					uf.Union(x, y);
					uf.Union(x + n, y + n);
				}
			}
		}
		else
		{
			if (uf.Find(x) == uf.Find(y)) puts("NO");
			else
			{
				puts("YES");
				if (uf.Find(x) != uf.Find(y + n))
				{
					uf.Union(x, y + n);
					uf.Union(x + n, y);
				}
			}
		}
	}
	while (q--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int x = ms[s1], y = ms[s2];
		if (uf.Find(x) == uf.Find(y)) puts("1");
		else if (uf.Find(x) == uf.Find(y + n)) puts("2");
		else puts("3");
	}
	return 0;
}