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
stringstream ins;
vector<string> v[N];
int tot = 0;
bool dfs(int cur = 1)
{
	string str;
	int n;
	tot = max(tot, cur);
	if (ins >> str >> n)
	{
		v[cur].push_back(str);
		while (n--)
		{
			dfs(cur + 1);
		}
		return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	for (auto &c : str) if (c == ',') c = ' ';
	ins << str;
	while (dfs());
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
	{
		for (auto &str : v[i]) printf("%s ", str.c_str());
		puts("");
	}
	return 0;
}