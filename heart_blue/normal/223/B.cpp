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
int pre[N];
int pos[N];
char s1[N];
char s2[N];
set<int> s[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1), m = strlen(s2 + 1);
	int ptr = 1;
	for (int i = 1; i <= m; i++)
	{
		while (ptr <= n && s1[ptr] != s2[i]) ptr++;
		pre[i] = ptr++;
	}
	ptr = n;
	for (int i = m; i >= 1; i--)
	{
		while (ptr > 0 && s1[ptr] != s2[i]) ptr--;
		pos[i] = ptr--;
	}
	if (pre[1] != 1 || pos[m] != n || pre[m] > n)
	{
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		s[s1[i]].insert(i);
	}
	for (int i = 1; i <= m; i++)
	{
		auto& sp = s[s2[i]];
		int l = pre[i], r = pos[i];
		while (1)
		{
			auto iter = sp.lower_bound(l);
			if (iter == sp.end()) break;
			if (*iter > r) break;
			sp.erase(iter);
		}
	}
	for (int i = 0; i < 200; i++)
	{
		if (!s[i].empty())
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}