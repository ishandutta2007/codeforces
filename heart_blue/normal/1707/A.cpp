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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		reverse(v.begin(), v.end());
		int cur = 0;
		string str;
		str.reserve(n);
		for (auto& x : v)
		{
			if (cur >= x) str += '1';
			else if (cur < q) cur++, str += '1';
			else str += '0';
		}
		reverse(str.begin(), str.end());
		puts(str.c_str());
	}
	return 0;
}