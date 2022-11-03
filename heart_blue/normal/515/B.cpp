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
const int N = 1e3 + 10;
int flag[N];
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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	uf.init();
	MEM(flag, 0);
	int b, g;
	cin >> b;
	while (b--)
	{
		int x;
		cin >> x;
		flag[x] = 1;
	}
	cin >> g;
	while (g--)
	{
		int x;
		cin >> x;
		flag[x + n] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int cur = i%m;
		for (int j = 0; j < m; j++)
		{
			if (uf.Find(i) != uf.Find(cur + n))
			{
				uf.Union(i, cur + n);
			}
			cur = (cur + n) % m;
		}
	}
	for (int i = 0; i < n + m; i++)
	{
		for (int j = 0; j < n + m; j++)
		{
			if (uf.Find(i) == uf.Find(j))
			{
				flag[i] = flag[j] = flag[i] | flag[j];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n + m; i++) sum += flag[i];
	if (sum == n + m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}