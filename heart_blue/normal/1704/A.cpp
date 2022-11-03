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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		string s1, s2;
		cin >> n >> m;
		cin >> s1 >> s2;
		reverse(s2.begin(), s2.end());
		reverse(s1.begin(), s1.end());
		if (s1.substr(0, m - 1) != s2.substr(0, m - 1))
		{
			puts("NO");
			continue;
		}
		if (count(s1.begin() + m - 1, s1.end(), s2.back())) puts("YES");
		else puts("NO");
	}
	return 0;
}