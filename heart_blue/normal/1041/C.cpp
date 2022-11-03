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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s.insert({ x,i });
	}
	int o = 0;
	while (!s.empty())
	{
		int x = -INF;
		o++;
		while (1)
		{
			auto iter = s.upper_bound({ x,(int)INF });
			if (iter == s.end()) break;
			ans[iter->second] = o;
			x = iter->first + d;
			s.erase(iter);
		}
	}
	printf("%d\n", o);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	
	return 0;
}