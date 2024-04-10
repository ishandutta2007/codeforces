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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const int MOD = 998244353;
class Trie
{
public:
	static const int K = 29;
	static const int M = 2;
	int ch[N * 30][M];
	int k;
	void init()
	{
		k = 0;
		newnode();
	}
	int newnode()
	{
		MEM(ch[k], 0);
		return k++;
	}
	void add(int x)
	{
		int o = 0;
		for (int i = K; i >= 0; i--)
		{
			int& t = ch[o][x >> i & 1];
			if (t == 0) t = newnode();
			o = t;
		}
	}
	int dfs(int x, int y, int cur)
	{
		if (cur == -1) return 0;
		int ret = 1 << 30;
		for (int o = 0; o < 2; o++)
		{
			for (int o1 = 0; o1 < 2; o1++)
			{
				int o2 = o ^ o1;
				if (ch[x][o1] && ch[y][o2])
				{
					ret = min(ret, dfs(ch[x][o1], ch[y][o2], cur - 1) + ((o1 ^ o2) << cur));
				}
			}
			if (ret != (1 << 30)) break;
		}
		return ret;
	}
	LL solve(int o = 0, int cur = K)
	{
		LL ret = 0;
		if (ch[o][0]) ret += solve(ch[o][0], cur - 1);
		if (ch[o][1]) ret += solve(ch[o][1], cur - 1);
		if (ch[o][0] && ch[o][1])
		{
			ret += dfs(ch[o][0], ch[o][1], cur - 1) + (1 << cur);
		}
		return ret;
	}

} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	trie.init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		trie.add(x);
	}
	printf("%lld\n", trie.solve());
	return 0;
}