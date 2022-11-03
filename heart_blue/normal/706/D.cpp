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
const int N = 1e7 + 10;
const int M = 2;
class Trie
{
	int ch[N][M];
	int sz[N];
	int k;
	inline int idx(char c)
	{
		return c - '0';
	}
	int newNode()
	{
		MEM(ch[k], -1);
		return k++;
	}
public:
	void init()
	{
		k = 0;
		MEM(ch[k++], -1);
	}
	void insert(char *str)
	{
		int o = 0;
		sz[o]++;
		for (int i = 0; str[i]; i++)
		{
			int &t = ch[o][idx(str[i])];
			if (t == -1) t = newNode();
			o = t;
			sz[o]++;
		}
	}
	void remove(char *str)
	{
		int o = 0;
		sz[o]--;
		for (int i = 0; str[i]; i++)
		{
			int &t = ch[o][idx(str[i])];
			o = t;
			sz[o]--;
		}
	}
	void getans(char *str)
	{
		int ret = 0;
		int o = 0;
		for (int i = 0; str[i]; i++)
		{
			ret <<= 1;
			int &t = ch[o][idx(str[i]) ^ 1];
			if (t != -1 && sz[t] > 0)
			{
				ret |= 1;
				o = t;
			}
			else
			{
				o = ch[o][idx(str[i])];
			}
		}
		printf("%d\n", ret);
	}
} trie;
char str[100];
void change(int x)
{
	int len = 31;
	str[len] = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		str[i] = (x & 1)+ '0';
		x >>= 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	trie.init();
	int q;
	scanf("%d", &q);
	change(0);
	trie.insert(str);
	while (q--)
	{
		char op[10];
		int x;
		scanf("%s %d", op, &x);
		change(x);
		if (op[0] == '+')
			trie.insert(str);
		else if (op[0] == '-')
			trie.remove(str);
		else
			trie.getans(str);
	}
	return 0;
}