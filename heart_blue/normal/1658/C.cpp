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
const int N = 1e6 + 10;
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
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		if (count(v.begin(), v.end(), 1) != 1)
		{
			puts("NO");
			continue;
		}
		rotate(v.begin(), find(v.begin(), v.end(), 1), v.end());
		int flag = 1;
		for (int i = 1; i < n; i++)
		{
			if (v[i] - v[i - 1] > 1)
				flag = 0;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}