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
const int N = 30 * 2e5 + 10;
class Trie
{
public:
	static const int M = 2;
	int ch[N][M];
	int sz[N];
	int k;
	void init()
	{
		k = 0;
		newnode();
	}
	int newnode()
	{
		MEM(ch[k], 0);
		sz[k] = 0;
		return k++;
	}
	inline int id(char c)
	{
		return c - 'A';
	}
	void add(int x)
	{
		int o = 0;
		for (int i = 29; i >= 0; i--)
		{
			int& t = ch[o][x >> i & 1];
			if (t == 0) t = newnode();
			o = t;
			sz[o]++;
		}
	}
	void dfs(int& ans, int sum = 0, int o = 0)
	{
		if (sz[o] == 1)
		{
			ans = min(ans, sum);
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int t = ch[o][i];
			if (t == 0) continue;
			dfs(ans, sum + max(0, sz[ch[o][i ^ 1]] - 1), t);
		}
	}

} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	trie.init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		trie.add(x);
	}
	int ans = INF;
	trie.dfs(ans);
	printf("%d\n", ans);
	return 0;
}