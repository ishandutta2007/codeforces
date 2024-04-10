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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> vp1, vp2;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x < y) vp1.emplace_back(y, i);
		else vp2.emplace_back(x, i);
	}
	sort(vp1.rbegin(), vp1.rend());
	sort(vp2.begin(), vp2.end());
	auto ans = vp1;
	if (ans.size() < vp2.size()) ans = vp2;
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d ", p.second);
	return 0;
}