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
const int N = 1e6 + 10;
vector<string> vs;
string ans = string(40, 'a');
string str;
bool check(string &str)
{
	for (auto &s : vs)
	{
		if (s.find(str) != -1)
		{
			return false;
		}
	}
	return true;
}
void dfs(int cur)
{
	if (cur >= ans.length()) return;
	if (cur > 0)
	{
		if (check(str))
		{
			ans = str;
			return;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		str.push_back(i);
		dfs(cur + 1);
		str.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vs.resize(n);
	for (auto &str : vs) cin >> str;
	dfs(0);
	cout << ans << endl;
	return 0;
}