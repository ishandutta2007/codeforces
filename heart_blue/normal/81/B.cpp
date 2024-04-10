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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
map<int, map<int, int>> mp;
vector<int> ans;
void dfs(int x, int fa = -1)
{
	ans.push_back(x);
	for (auto &p : mp[x])
	{
		int y = p.first;
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	string ans = string(1, ' ');
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c == ' ') continue;
		if (isdigit(c))
		{
			if (i > 0 && str[i - 1] == ' ' && isdigit(ans.back())) ans.push_back(' ');
		}
		if (c == '.')
		{
			cnt++;
			if (cnt == 3)
			{
				if (ans.back() != ' ') ans.push_back(' ');
				ans += "...";
				cnt = 0;
			}
			continue;
		}
		ans.push_back(c);
		if (c == ',') ans.push_back(' ');
	}
	if (ans.back() == ' ') ans.pop_back();
	cout << ans.substr(1) << endl;
	return 0;
}