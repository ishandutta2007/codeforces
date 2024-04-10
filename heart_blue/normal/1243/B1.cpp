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
LL multy(LL x, LL y)
{
	if (x > 4 * INF * INF / y) return 4 * INF * INF;
	else return x * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i])
				v.push_back(i);
		}
		if (v.size() == 1 || v.size() > 2)
		{
			puts("No");
			continue;
		}
		if (v.size() == 2)
		{
			swap(s1[v[0]], s2[v[1]]);
		}
		if (s1 == s2) puts("Yes");
		else puts("No");
	}
	return 0;
}