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
const int N = 2e6 + 10;
int dp[N];
vector<string> vs;
string str;
class Trie
{
	int ch[N][26];
	int val[N];
	int k;
public:
	int newnode()
	{
		MEM(ch[k], 0);
		return k++;
	}
	void init()
	{
		k = 0;
		newnode();
	}
	void insert(string str, int key)
	{
		int o = 0;
		reverse(str.begin(), str.end());
		for (auto c : str)
		{
			c = tolower(c);
			c -= 'a';
			if (ch[o][c] == 0) ch[o][c] = newnode();
			o = ch[o][c];
		}
		val[o] = key;
	}
	void getans(int l, int len)
	{
		int o = 0;
		for (int i = l; i < len; i++)
		{
			o = ch[o][str[i] - 'a'];
			if (o == 0) break;
			if (val[o] && dp[i + 1])
			{
				dp[l] = val[o];
				break;
			}
		}
	}
} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len;
	cin >> len >> str;
	int n;
	cin >> n;
	vs.resize(n + 1);
	trie.init();
	for (int i = 1; i <= n; i++) cin >> vs[i], trie.insert(vs[i], i);
	dp[len] = 1;
	for (int i = len - 1; i >= 0; i--) 
		trie.getans(i, min(i + 1010, len));
	int o = 0;
	while (o < len)
	{
		printf("%s ", vs[dp[o]].c_str());
		o += vs[dp[o]].length();
	}
	return 0;
}