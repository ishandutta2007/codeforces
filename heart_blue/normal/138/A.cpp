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
const int N = 2e2 + 10;
int flag[N];
map<string, int> ms;
void init()
{
	string vowel = "aeiou";
	for (auto &c : vowel) flag[c] = 1;
	ms["aaaa"] = 1;
	ms["abab"] = 1;
	ms["abba"] = 1;
	ms["aabb"] = 1;
}
bool refrain(string &str, int k)
{
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.length(); i++)
	{
		if (!flag[str[i]]) continue;
		k--;
		if (k == 0)
		{
			str = str.substr(0, i + 1);
			return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	init();
	cin >> n >> k;
	string ans = "aaaa";
	for (int i = 0; i < n; i++)
	{
		string s[4];
		for (int o = 0; o < 4; o++)
		{
			cin >> s[o];
			if (!refrain(s[o], k))
			{
				puts("NO");
				return 0;
			}
		}
		string ret = "aaaa";
		for (int o = 0; o < 4; o++)
		{
			if (s[0] != s[o]) ret[o] = 'b';
		}
		for (int o = 0; o < 4; o++)
		{
			if (ret[o] == 'a') continue;
			for (int oo = o + 1; oo < 4; oo++)
			{
				if (ret[oo] == 'a') continue;
				if (s[o] != s[oo])
				{
					puts("NO");
					return 0;
				}
			}
		}
		if (ret == "aaaa") continue;
		if (!ms.count(ret))
		{
			puts("NO");
			return 0;
		}
		if (ans == "aaaa" || ans == ret) ans = ret;
		else
		{
			puts("NO");
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}