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
const int N = 3e6 + 10;
class Trie
{
public:
	static const int M = 2;
	static const int K = 29;
	int ch[N][M];
	int sum[N];
	int k;
	void init()
	{
		k = 0;
		newnode();
	}
	int newnode()
	{
		MEM(ch[k], 0);
		sum[k] = 0;
		return k++;
	}
	inline int id(char c)
	{
		return c - 'A';
	}
	void add(int x, int val, int cur = K, int o = 0)
	{
		if (o) sum[o] += val;
		if (cur < 0) return;
		int& t = ch[o][x >> cur & 1];
		if (t == 0) t = newnode();
		add(x, val, cur - 1, t);
	}
	int getans(int x, int val, int cur = K, int o = 0)
	{
		if (cur < 0) return 0;
		int ret = 0;
		for (int i = 0; i < 2; i++)
		{
			int o1 = (x >> cur & 1) ^ i;
			int o2 = val >> cur & 1;
			if (o1 > o2) continue;
			if (o1 < o2) ret += sum[ch[o][i]];
			else
			{
				if (ch[o][i])
					ret += getans(x, val, cur - 1, ch[o][i]);
			}
		}
		return ret;
	}
} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	trie.init();
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op, x, val;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			trie.add(x, 1);
		}
		else if (op == 2)
		{
			trie.add(x, -1);
		}
		else
		{
			scanf("%d", &val);
			printf("%d\n", trie.getans(x, val));
		}

	}

	return 0;
}