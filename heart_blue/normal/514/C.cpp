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
const int N = 1e6 + 10;
const int M = 3;
char s[N];
class Trie
{
	int ch[N][M];
	int sz[N];
	int k;
	inline int idx(char c)
	{
		return c - 'a';
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
	bool getans(char *str, int o = 0, int cnt = 1)
	{
		if (o == -1) return false;
		if (cnt < 0) return false;
		if (*str == 0)
		{
			return cnt == 0;
		}
		for (int i = 0; i < 3; i++)
		{
			if (getans(str + 1, ch[o][i], cnt - (*str != (i + 'a'))))
			{
				return true;
			}
		}
		return false;
	}
} trie;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	trie.init();
	while (n--)
	{
		scanf("%s", s);
		trie.insert(s);
	}
	while (q--)
	{
		scanf("%s", s);
		if (trie.getans(s)) puts("YES");
		else puts("NO");
	}
	return 0;
}