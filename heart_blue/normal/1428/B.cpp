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
const int N = 3e5 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf1;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int sz;
		scanf("%d", &sz);
		string str;
		cin >> str;
		
		uf1.init(sz);
		int cnt1 = count(str.begin(), str.end(), '<');
		int cnt2 = count(str.begin(), str.end(), '>');
		if (cnt1 > 0 && cnt2 > 0)
		{
			for (int i = 0; i < sz; i++)
			{
				if (str[i] != '-') continue;
				int x = i;
				int y = (i + 1) % sz;
				if (uf1.Find(x) == uf1.Find(y)) continue;
				uf1.Union(x, y);
			}
			int ans = 0;
			for (int i = 0; i < sz; i++)
			{
				if (uf1.Find(i) != i) continue;
				int cnt = uf1.treesize(i);
				if (cnt > 1) ans += cnt;
			}
			printf("%d\n", ans);
		}
		else
		{
			printf("%d\n", sz);
		}
		
	}
	return 0;
}