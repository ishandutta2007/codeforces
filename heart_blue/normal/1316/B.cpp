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
const int N = 4e5 + 10;


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
		string str;
		cin >> str;
		pair<string, int> ans;
		ans.first = str;
		ans.second = 1;
		for (int i = 2; i <= n; i++)
		{
			string s1 = str.substr(i - 1);
			string s2 = str.substr(0, i - 1);
			if ((n - i + 1) & 1) reverse(s2.begin(), s2.end());
			ans = min(ans, { s1 + s2, i });
		}
		puts(ans.first.c_str());
		printf("%d\n", ans.second);
	}
	return 0;
}