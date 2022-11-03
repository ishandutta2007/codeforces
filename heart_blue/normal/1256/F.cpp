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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
bool check(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}
int getcnt(string& str)
{
	int tot = 0;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] > str[j])
				tot++;
		}
	}
	return tot & 1;
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
		scanf("%d", &n);
		string s1, s2;
		cin >> s1 >> s2;
		if (!check(s1, s2))
		{
			puts("NO");
			continue;
		}
		int maxv = 0;
		for (auto& c : s1)
		{
			int cnt = count(s1.begin(), s1.end(), c);
			maxv = max(maxv, cnt);
			if (maxv >= 2) break;
		}
		if (maxv >= 2)
		{
			puts("YES");
			continue;
		}
		if (getcnt(s1) == getcnt(s2)) puts("YES");
		else puts("NO");
	}
	return 0;
}