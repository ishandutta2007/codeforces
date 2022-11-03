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
const int N = 5e4 + 10;
class UnionSet
{
public:
	int fa[N];
	int dis[N];
	void init()
	{
		MEM(fa, -1);
		MEM(dis, 0);
	}
	int getDis(int x)
	{
		Find(x);
		return dis[x];
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		int d = 0;
		while (fa[root] >= 0)
		{
			d += dis[root];
			root = fa[root];
		}
		while (x != root)
		{
			tie(d, dis[x]) = make_pair(d - dis[x], d);
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y, int w)
	{
		int px = Find(x);
		int py = Find(y);
		//if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
		dis[py] = dis[x] + w - dis[y];
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, a, b;
	string str;
	cin >> n >> a >> b >> str;
	int ca = -1, cb = -1;
	for (int i = 0; i *a <= n; i++)
	{
		int r = n - i*a;
		if (r%b == 0)
		{
			ca = i;
			cb = r / b;
			break;
		}
	}
	if (ca == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ca + cb << endl;
	int cur = 0;
	for (int i = 0; i < ca; i++) cout << str.substr(cur, a) << endl, cur += a;
	for (int i = 0; i < cb; i++) cout << str.substr(cur, b) << endl, cur += b;
	return 0;
}