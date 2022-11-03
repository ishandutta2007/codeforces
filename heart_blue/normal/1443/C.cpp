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
const int N = 2e3 + 10;

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
		vector<pair<int, int>> vp(n);
		LL tot = 0;
		for (auto& p : vp) scanf("%d", &p.first);
		for (auto& p : vp) scanf("%d", &p.second), tot += p.second;
		sort(vp.begin(), vp.end());
		LL ans = tot;
		int maxv = 0;
		for (auto& p : vp)
		{
			maxv = max(maxv, p.first);
			tot -= p.second;
			ans = min(ans, max(maxv * 1LL, tot));
		}
		printf("%d\n", ans);
	}
	return 0;
}