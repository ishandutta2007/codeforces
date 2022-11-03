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
const int N = 1e3 + 10;
vector<int> v[N];
string ans[N];
void dfs(string& str, int& rest, int cur = 0)
{
	if (rest == 0) return;
	if (!v[cur].empty())
	{
		ans[v[cur].back()] = str;
		v[cur].pop_back();
		rest--;
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		str.push_back(i + '0');
		dfs(str, rest, cur + 1);
		str.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	int tot = n;
	string str;
	dfs(str, tot);
	if (tot != 0) puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i++)
			puts(ans[i].c_str());
	}
	return 0;
}