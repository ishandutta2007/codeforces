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
const int N = 2e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	int n;
	cin >> n;
	while (n--)
	{
		int x, w;
		cin >> x >> w;
		vp.push_back({ x + w,x - w });
	}
	sort(vp.begin(), vp.end());
	int cur = -INF * 2;
	int ans = 0;
	for (auto &p : vp)
	{
		if (p.second < cur) continue;
		ans++;
		cur = p.first;
	}
	cout << ans << endl;
	return 0;
}