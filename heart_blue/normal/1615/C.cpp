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
const int N = 5e3 + 10;
int solve(string& s1, string& s2)
{
	int cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] == '1') cnt1++;
			else cnt0++;
		}
	}
	if (cnt1 == cnt0) return cnt0 * 2;
	else return INF;
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
		int ans = solve(s1, s2);
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == s2[i] && s1[i] == '1')
			{
				for (int j = 0; j < s1.length(); j++)
				{
					if (j != i)
						s1[j] ^= 1;
				}
				ans = min(ans, solve(s1, s2) + 1);
				break;
			}
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}