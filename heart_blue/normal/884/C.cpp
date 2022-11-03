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
const int N = 1e5 + 10;
class UnionFind
{
private:
	int a[N];
public:
	void init(int n = N)
	{
		memset(a, -1, sizeof(int)*n);
	}
	int Find(int x)
	{
		int p = x;
		while (a[p] >= 0) p = a[p];
		while (x != p)
		{
			int tmp = a[x];
			a[x] = p;
			x = tmp;
		}
		return p;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (a[px] < a[py]) swap(px, py);
		a[py] += a[px];
		a[px] = py;
	}
	int treesize(int x)
	{
		int px = Find(x);
		return -a[px];
	}
} uf;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (uf.Find(i) != uf.Find(x))
		{
			uf.Union(i, x);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
			ans.push_back(uf.treesize(i));
	}
	ans.push_back(0);
	sort(ans.begin(), ans.end());
	int x = ans.back();
	ans.pop_back();
	ans.back() += x;
	LL res = 0;
	for (auto &x : ans)
	{
		res += 1LL * x*x;
	}
	cout << res << endl;
	return 0;
}