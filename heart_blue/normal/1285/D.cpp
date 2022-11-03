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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e6 + 10;
class Trie
{
public:
	int ch[N][2];
	int k = 0;
	int newnode()
	{
		ch[k][0] = ch[k][1] = 0;
		return k++;
	}
	void init()
	{
		k = 0;
		newnode();
	}
	void add(int x)
	{
		int o = 0;
		for (int i = 29; i >= 0; i--)
		{
			int oo = x >> i & 1;
			if (ch[o][oo] == 0) ch[o][oo] = newnode();
			o = ch[o][oo];
		}
	}
	int dfs(int o = 0, int cur = 29, int sum = 0)
	{
		if (cur == -1)
		{
			return sum;
		}
		if (ch[o][0] && ch[o][1])
		{
			return min(dfs(ch[o][0], cur - 1, 1 << cur | sum), dfs(ch[o][1], cur - 1, 1 << cur | sum));
		}
		if (ch[o][0]) return dfs(ch[o][0], cur - 1, sum);
		else return dfs(ch[o][1], cur - 1, sum);
	}
} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	trie.init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		trie.add(x);
	}
	printf("%d\n", trie.dfs());
	return 0;
}