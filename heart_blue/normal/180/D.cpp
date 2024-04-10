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
int len;
string ans;
string s1, s2;
int cnt[200];
void dfs(int cur = 0, bool flag = true)
{
	if (cur == len)
	{
		if (flag) return;
		else puts(ans.c_str()), exit(0);
	}
	if (cur == s1.length())
	{
		if (flag) return;
		else puts(ans.c_str()), exit(0);
	}
	char low = flag ? s2[cur] : 'a';
	for (int i = low; i <= 'z'; i++)
	{
		if (cnt[i] == 0) continue;
		cnt[i]--;
		ans.push_back(i);
		dfs(cur + 1, flag && i == s2[cur]);
		cnt[i]++;
		ans.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s1 >> s2;
	while (s2.length() < s1.length())
		s2 += 'a' - 1;
	len = s2.length();
	for (auto& c : s1)
		cnt[c]++;
	dfs();
	puts("-1");
	return 0;
}