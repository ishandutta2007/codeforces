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
vector<int> v[N];
int k = 0;
bool dfs(int x = 0)
{
	string str;
	if (cin >> str)
	{
		if (str == "pair")
		{
			for (int i = 0; i < 2; i++)
			{
				v[x].push_back(++k);
				if (!dfs(k)) return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
void solve(int x = 0)
{
	if (v[x].empty())
	{
		printf("int");
	}
	else
	{
		printf("pair");
		putchar('<');
		solve(v[x][0]);
		putchar(',');
		solve(v[x][1]);
		putchar('>');
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (!dfs())
	{
		puts("Error occurred");
		return 0;
	}
	string str;
	if (cin >> str)
	{
		puts("Error occurred");
		return 0;
	}
	solve();
	return 0;
}