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
const int M = 26;
char s[N];
class Trie
{
	int ch[N][M];
	int win[N];
	int lose[N];
	int sz[N];
	int k;
	inline int idx(char c)
	{
		return c - 'a';
	}
	int newNode()
	{
		sz[k] = 0;
		MEM(ch[k], -1);
		return k++;
	}
public:
	void init()
	{
		k = 0;
		sz[0] = 0;
		MEM(ch[k++], -1);
	}
	void insert(char *str)
	{
		int o = 0;
		for (int i = 0; str[i]; i++)
		{
			int &t = ch[o][idx(str[i])];
			if (t == -1) t = newNode(), sz[o]++;
			o = t;
		}
	}
	void check(int o)
	{
		if (o == -1) return;
		win[o] = lose[o] = 0;
		if (sz[o] == 0)
		{
			lose[o] = 1;
		}
		for (int i = 0; i < 26; i++)
		{
			check(ch[o][i]);
			if (ch[o][i] != -1)
			{
				win[o] |= !win[ch[o][i]];
				lose[o] |= !lose[ch[o][i]];
			}
		}
	}
	bool getans(int k)
	{
		if (win[0] == 1 && lose[0] == 1) return true;
		if (win[0] == 0) return false;
		return k % 2 == 1;
	}
} trie;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	trie.init();
	while (n--)
	{
		scanf("%s", s);
		trie.insert(s);
	}
	trie.check(0);
	if (trie.getans(k)) puts("First");
	else puts("Second");
	return 0;
}