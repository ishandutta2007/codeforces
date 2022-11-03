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
const int N = 2e5 + 10;
const int MOD = 998244353;
int dp[N];
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
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> L,R;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		R[x] = i;
		if (!L.count(x)) L[x] = i;
	}
	vector<pair<int, int>> vp;
	for (auto& p : L)
	{
		vp.emplace_back(p.second, R[p.first]);
	}
	sort(vp.begin(), vp.end());
	uf.init();
	for (auto& p : vp)
	{
		int l, r;
		tie(l, r) = p;
		for (int i = r - 1; i >= l; i--)
		{
			if (uf.Find(i) != uf.Find(i + 1))
				uf.Union(i, i + 1);
			else
				break;
		}
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (uf.Find(i) == uf.Find(i - 1))dp[i] = dp[i - 1];
		else dp[i] = 2 * dp[i - 1] % MOD;
	}
	cout << dp[n] << endl;
	return 0;
}