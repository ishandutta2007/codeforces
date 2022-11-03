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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e1 + 10;
int flag[N][N];
int vis[N];
int n;
int k;
string str;
void dfs(int x)
{
	if (vis[x] == 0) str += x + 'a';
	vis[x] = 1;
	str += x + 'a';
	for (int i = x + 1; i < k; i++)
	{
		if (flag[x][i]) continue;
		flag[x][i] = 1;
		dfs(i);
		str += x + 'a';
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	dfs(0);
	char c = str.back();
	while (str.length() > n) str.pop_back();
	int cur = 1;
	if (cur == str.length())
		cur = 0;
	while (str.length() < n)
	{
		str += str[cur++];
	}
	puts(str.c_str());
	return 0;
}