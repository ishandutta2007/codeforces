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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> v1(n), v2(m);
		for (auto& x : v1) scanf("%d", &x);
		for (auto& x : v2) scanf("%d", &x);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int ans = -1;
		while (!v1.empty() && !v2.empty())
		{
			if (v1.back() > v2.back()) v1.pop_back();
			else if (v1.back() < v2.back()) v2.pop_back();
			else
			{
				ans = v1.back();
				break;
			}
		}
		if (ans == -1) puts("NO");
		else
		{
			puts("YES");
			printf("1 %d\n", ans);
		}
	}
	return 0;
}