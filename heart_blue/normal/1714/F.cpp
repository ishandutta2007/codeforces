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
const int N = 2e5 + 10;
void solve(int n, int a, int b, int c, int dab, int dac, int dbc)
{
	if (dac + dbc < dab)
	{
		puts("NO");
		return;
	}
	if ((dac + dbc - dab) & 1)
	{
		puts("NO");
		return;
	}
	int o = (dac + dbc - dab) / 2;
	int cost = dab + 1 + o;
	if (cost > n)
	{
		puts("NO");
		return;
	}
	vector<int> v1, v2;
	v1.push_back(a);
	int cur = 4;
	for (int i = 1; i < dab; i++)
	{
		if (i == dac - o && o == 0)
			v1.push_back(c);
		else
		{
			v1.push_back(cur++);
		}
	}
	v1.push_back(b);
	if (o > 0)
	{
		v2.push_back(v1[dac - o]);
		for (int i = 1; i < o; i++)
			v2.push_back(cur++);
		v2.push_back(c);
	}
	puts("YES");
	for (int i = 0; i + 1 < v1.size(); i++)
	{
		printf("%d %d\n", v1[i], v1[i + 1]);
	}
	for (int i = 0; i + 1 < v2.size(); i++)
	{
		printf("%d %d\n", v2[i], v2[i + 1]);
	}
	while (cur <= n)
		printf("1 %d\n", cur++);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a = 1, b = 2, c = 3;
		int dab, dbc, dac;
		int n;
		scanf("%d", &n);
		scanf("%d%d%d", &dab, &dbc, &dac);
		int maxv = max({ dab,dbc,dac });
		if (maxv == dab)
			solve(n, a, b, c, dab, dac, dbc);
		else if (maxv == dac)
			solve(n, a, c, b, dac, dab, dbc);
		else
			solve(n, b, c, a, dbc, dab, dac);

	}
	return 0;
}