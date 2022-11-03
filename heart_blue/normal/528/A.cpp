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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int Q[N], H[N], V[N];
LL ans[N];
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf[2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int w, h, q;
	cin >> w >> h >> q;
	string query(q, 'V');
	MEM(V, 0);
	MEM(H, 0);
	uf[0].init();
	uf[1].init();
	for (int i = 0; i < q; i++)
	{
		cin >> query[i] >> Q[i];
		if (query[i] == 'V') V[Q[i]]++;
		else H[Q[i]]++;
	}
	int maxw = 1, maxh = 1;
	for (int i = 1; i < w; i++)
	{
		if (!V[i])
		{
			uf[0].Union(i, i + 1);
			maxw = max(maxw, uf[0].treesize(i));
		}
	}
	for (int i = 1; i < h; i++)
	{
		if (!H[i])
		{
			uf[1].Union(i, i + 1);
			maxh = max(maxh, uf[1].treesize(i));
		}
	}
	for (int i = q - 1; i >= 0; i--)
	{
		ans[i] = (LL)maxh*maxw;
		char c = query[i];
		if (c == 'V')
		{
			V[Q[i]]--;
			if (V[Q[i]] == 0)
			{
				uf[0].Union(Q[i], Q[i] + 1);
				maxw = max(maxw, uf[0].treesize(Q[i]));
			}
		}
		else
		{
			H[Q[i]]--;
			if (H[Q[i]] == 0)
			{
				uf[1].Union(Q[i], Q[i] + 1);
				maxh = max(maxh, uf[1].treesize(Q[i]));
			}
		}
		
	}
	for (int i = 0; i < q; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}