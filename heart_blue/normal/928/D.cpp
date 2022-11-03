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
class Trie
{
public:
	int ch[N][26];
	int val[N];
	int sz[N];
	int k;
	inline int id(char c)
	{
		return c - 'a';
	}
	inline int newnode()
	{
		MEM(ch[k], 0);
		val[k] = 0;
		sz[k] = 0;
		return k++;
	}
	void init()
	{
		k = 0;
		newnode();
	}
	int add(string &str)
	{
		str.push_back('.');
		int o = 0;
		vector<int> s;
		int ans = 0;
		int flag = 0;
		int cost = 0;
		for (auto &c : str)
		{
			if (islower(c))
			{
				if (!ch[o][id(c)]) ch[o][id(c)] = newnode();
				o = ch[o][id(c)];
				if (flag) cost++;
				if (o != 0 && val[o] == 1 && cost > 0)
					ans += cost - 1;
				if (sz[o] == 1) flag = 1;
				s.push_back(o);
			}
			else
			{
				if (val[o])
				{
					s.clear();
				}
				else val[o] = 1;
				while (!s.empty())
				{
					int x = s.back();
					s.pop_back();
					sz[x]++;
				}
				o = 0;
				flag = 0;
				cost = 0;
				val[0] = 0;
			}
		}
		return ans;
	}

} trie;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	trie.init();
	int ans = 0;
	int tot = 0;
	int sz = 0;
	while (getline(cin, str))
	{
		tot++;
		ans += str.length();
		sz += str.length();
		int x = trie.add(str);
		ans -= x;
		//cout << str << endl;
		//cout << str.length() << ' ';
		//cout << x << endl;
	}
	//cout << sz + tot << endl;
	cout << tot + ans << endl;
	return 0;
}