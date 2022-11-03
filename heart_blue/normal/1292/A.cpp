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
const int N = 2e5 + 10;
int flag[N][2];
set<pair<int, int>> s;
void check(int x)
{
	for (int i = 0; i < 2; i++)
	{
		if (flag[x][i] && flag[x + 1][i ^ 1]) s.emplace(x, i);
		else s.erase(make_pair(x, i));
	}
	if (flag[x][0] && flag[x][1]) s.emplace(x, -1);
	else s.erase(make_pair(x, -1));
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		r--;
		flag[c][r] ^= 1;
		check(c);
		check(c - 1);
		if (s.empty()) puts("Yes");
		else puts("No");
	}
	return 0;
}