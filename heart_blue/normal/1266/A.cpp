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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s;
		cin >> s;
		if (count(s.begin(), s.end(), '0') == 0)
		{
			puts("cyan");
			continue;
		}
		int tot = 0;
		int cnt = 0;
		for (auto& c : s) tot += c - '0', cnt += (c - '0') & 1;
		cnt = s.length() - cnt;
		if (tot % 3 == 0 && cnt > 1) puts("red");
		else puts("cyan");
	}
	return 0;
}