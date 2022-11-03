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
const int N = 1e2 + 10;
int cnt[N];
string ans;
bool solve(string &s, int len)
{
	if (s.length() == len)
	{
		cout << ans << endl;
		return true;
	}
	for (int i = s[len] - '0'; i >= 0; i--)
	{
		if (cnt[i] == 0) continue;
		cnt[i]--;
		ans += i + '0';
		if (i + '0' != s[len])
		{
			cout << ans;
			for (int o = 9; o >= 0; o--)
			{
				while (cnt[o]--) cout << o;
			}
			return true;
		}
		if (solve(s, len + 1)) return true;
		cnt[i]++;
		ans.pop_back();
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	for (auto &c : s1) cnt[c - '0']++;
	if (s1.length() < s2.length())
	{
		sort(s1.rbegin(), s1.rend());
		cout << s1 << endl;
		return 0;
	}
	solve(s2, 0);
	return 0;
}