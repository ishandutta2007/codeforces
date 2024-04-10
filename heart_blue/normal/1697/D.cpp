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
const int N = 1e3 + 10;
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
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int ask2(int l, int r)
{
	cout << "? 2 " << l << ' ' << r << endl;
	int ret;
	cin >> ret;
	return ret;
}
char ask1(int id)
{
	cout << "? 1 " << id << endl;
	char c;
	cin >> c;
	return c;
}
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		int key = v.size();
		int l = 0, r = key - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ask2(v[mid], i) == v.size() - mid + 1) r = mid - 1;
			else l = mid + 1, key = mid;
		}
		if (key != v.size())
		{
			uf.Union(v[key], i);
			v.erase(v.begin() + key);
		}
		v.push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
			str[i] = ask1(i);
	}
	for (int i = 1; i <= n; i++)
		str[i] = str[uf.Find(i)];
	cout << "! " << str + 1 << endl;
	return 0;
}