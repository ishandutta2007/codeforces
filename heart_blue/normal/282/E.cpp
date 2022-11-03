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
const int N = 7e6 + 10;
const int M = 1e5 + 10;
LL sum[N];
class Trie
{
	int ch[N][2];
	int k;
public:
	void init()
	{
		k = 0;
		newnode();
	}
	int newnode()
	{
		ch[k][0] = ch[k][1] = 0;
		return k++;
	}
	void add(LL x)
	{
		int o = 0;
		for (int i = 60; i >= 0; i--)
		{
			int &t = ch[o][x >> i & 1];
			if (t == 0) t = newnode();
			o = t;
		}
	}
	LL getans(LL x)
	{
		int o = 0;
		for (int i = 60; i >= 0; i--)
		{
			int oo = x >> i & 1;
			int t = ch[o][oo ^ 1];
			if (t == 0)
			{
				x ^= oo << i;
				t = ch[o][oo];
			}
			else
			{
				x |= 1LL << i;
			}
			o = t;
		}
		return x;
	}
} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	trie.init();
	trie.add(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] ^= sum[i - 1];
	}
	LL ans = sum[n];
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, trie.getans(sum[i] ^ sum[n]));
		trie.add(sum[i]);
	}
	cout << ans << endl;
	return 0;
}