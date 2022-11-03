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
const int M = 20;
class Trie
{
public:
	int ch[N][2];
	int sz[N];
	int k;
	void init()
	{
		k = 0;
		newNode();
	}
	int newNode()
	{
		MEM(ch[k], 0);
		sz[k] = 0;
		return k++;
	}
	void add(int x)
	{
		vector<int> v;
		int cnt = M;
		while (cnt--) v.push_back(x & 1), x >>= 1;
		reverse(v.begin(), v.end());
		int o = 0;
		for (auto &x : v)
		{
			int &t = ch[o][x];
			if (t == 0) t = newNode();
			sz[t]++;
			o = t;
		}
	}
	int getans(int x)
	{
		vector<int> v;
		int cnt = M;
		while (cnt--) v.push_back(x & 1), x >>= 1;
		reverse(v.begin(), v.end());
		int o = 0;
		int oo = 1 << M;
		int ans = 0;
		for (auto &x : v)
		{
			oo >>= 1;
			if (ch[o][x] == 0)
			{
				break;
			}
			if (sz[ch[o][x]] < oo)
			{
				o = ch[o][x];
				continue;
			}
			ans |= oo;
			x ^= 1;
			if (ch[o][x] == 0) break;
			o = ch[o][x];
		}
		return ans;
	}
} trie;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	trie.init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (flag[x]) continue;
		flag[x] = 1;
		trie.add(x);
	}
	int sum = 0;
	while (q--)
	{
		int x;
		scanf("%d", &x);
		sum ^= x;
		printf("%d\n", trie.getans(sum));
	}
	return 0;
}