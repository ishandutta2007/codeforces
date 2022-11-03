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
const int N = 5e3 + 10;
vector<int> v[N];
int flag[N];
const int M = 2e6 + 10;
class Trie
{
public:
	int ch[M][26];
	int val[M];
	int k;
	inline int newNode()
	{
		MEM(ch[k], 0);
		val[k] = 1;
		return k++;
	}
	void init()
	{
		k = 0;
		newNode();
	}
	Trie()
	{
		init();
	}
	inline int id(char c)
	{
		return c - 'a';
	}
	int add(string &str, int l)
	{
		int ret = 0;
		int o = 0;
		for (int i = l; i < str.length(); i++)
		{
			int &t = ch[o][id(str[i])];
			if (t == 0) t = newNode();
			//cout << o << ' ' << t << endl;
			if (flag[i])
			{
				ret += val[t];
				//cout << t << endl;
				val[t] = 0;
			}
			o = t;
		}
		return ret;
	}
} trie;
void check(string &str, string &s, vector<int> &v)
{
	for (int i = 0; i + s.length() <= str.length(); i++)
	{
		if (str.substr(i, s.length()) == s) v.push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	string s1, s2;
	cin >> str >> s1 >> s2;
	vector<int> v1, v2;
	check(str, s1, v1);
	check(str, s2, v2);
	for (auto &x : v2) x += s2.length() - 1;
	map<int, int> m;
	for (auto &x : v1)
	{
		for (auto &y : v2)
		{
			if (x > y) continue;
			if (y - x + 1 < max(s1.length(), s2.length())) continue;
			if (y - x + 1 <= s1.length() + s2.length())
			{
				m[y - x + 1] = 1;
			}
			else
			{
				int o = y - x + 1 - s1.length() - s2.length();
				v[x + s1.length()].push_back(y - s2.length());
			}
		}
	}
	int ans = m.size();
	for (int i = 0; i < str.length(); i++)
	{
		MEM(flag, 0);
		for (auto &x : v[i]) flag[x] = 1;
		ans += trie.add(str, i);
	}
	cout << ans << endl;
	return 0;
}