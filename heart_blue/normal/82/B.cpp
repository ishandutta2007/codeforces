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
const int N = 2e2 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] > 0) s = p[s];
		while (x != s)
		{
			int tmp = p[x];
			p[x] = s;
			x = tmp;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] < p[py]) swap(x, y);
		p[py] += p[px];
		p[px] = py;
	}
} uf;
int a[N][N];
int flag[N];
vector<int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n;
	cin >> n;
	int o = n*(n - 1) / 2;
	if (n == 2)
	{
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &x : v) cin >> x;
		cout << 1 << ' ' << v.back() << endl;
		v.pop_back();
		cout << k - 1;
		for (auto &x : v) cout << ' ' << x;
		cout << endl;
		return 0;
	}
	while (o--)
	{
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &x : v) cin >> x, flag[x]++;
		for (int i = 0; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				a[v[i]][v[j]] = ++a[v[j]][v[i]];
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (flag[i] == 0) continue;
		for (int j = i + 1; j < N; j++)
		{
			if (flag[j] == 0) continue;
			if (a[i][j] == n - 1 && uf.Find(i) != uf.Find(j))
			{
				uf.Union(i, j);
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (flag[i] == 0) continue;
		ans[uf.Find(i)].push_back(i);
	}
	for (int i = 1; i < N; i++)
	{
		if (ans[i].empty()) continue;
		cout << ans[i].size();
		for (auto &x : ans[i]) cout << ' ' << x;
		cout << '\n';
	}
	return 0;
}