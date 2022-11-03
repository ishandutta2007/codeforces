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
map<string, int> ms;
map<string, int> key;
void add(const string& str)
{
	if (key.count(str))
		ms[str]++;
}
void del(const string& str)
{
	if (key.count(str))
		if (ms[str]-- == 1)
			ms.erase(str);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		key[s] = 1;
	}
	int ptr = 0;
	pair<int, int> ans = { 0,0 };
	for (int i = 0; i < str.length(); i++)
	{
		while (ptr < str.length() && ms.empty())
		{
			for (int j = 0; j < 10 && ptr - j >= i; j++)
			{
				add(str.substr(ptr - j, j + 1));
			}
			if (!ms.empty()) break;
			ptr++;
		}
		ans = max(ans, make_pair(ptr - i, i));
		for (int j = 1; j <= 10 && i + j <= ptr + 1 && i + j < str.length(); j++)
		{
			del(str.substr(i, j));
		}
	}
	if (ans.first == 0) ans.second = 0;
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}