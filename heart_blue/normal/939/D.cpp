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
#include <random>
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
	int size(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
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
		if (size(x) > size(y)) swap(px, py);
		p[py] += p[px];
		p[px] = py;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	vector<pair<char, char>> ans;
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		if (uf.Find(s1[i]) != uf.Find(s2[i]))
		{
			uf.Union(s1[i], s2[i]);
			ans.push_back({ s1[i],s2[i] });
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		printf("%c %c\n", p.first, p.second);
	}
	return 0;
}