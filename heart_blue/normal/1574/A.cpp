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
void dfs(string str, int cur, int& rest, int o = 0)
{
	if (o - cur > 0) return;
	if (rest == 0) return;
	if (cur == 0)
	{
		if (o == 0) cout << str << endl, rest--;
		return;
	}
	dfs(str + '(', cur - 1, rest, o + 1);
	dfs(str + ')', cur - 1, rest, o - 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		dfs("", n * 2, n);
	}
	return 0;
}