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
const int N = 1e5 + 10;
int check(const string &s1, const string &s2)
{
	int cnt = 0;
	int cur = 0;
	for (auto& c : s2)
	{
		cur = s1.find(c, cur);
		if (cur == s1.npos) break;
		cnt++;
		cur++;
	}
	return s1.length() + s2.length() - 2 * cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		LL x = 1;
		cin >> str;
		int ans = INF;
		while (x < 2 * INF * INF)
		{
			ans = min(ans, check(str, to_string(x)));
			x *= 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}