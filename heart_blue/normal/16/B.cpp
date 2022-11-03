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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	cin >> n >> m;
	vector<pair<LL, LL>> vp;
	for (int i = 0; i < m; i++)
	{
		LL a, b;
		cin >> a >> b;
		vp.push_back({ b,a });
	}
	sort(vp.rbegin(), vp.rend());
	LL ans = 0;
	for (auto &p : vp)
	{
		LL a, b;
		tie(b, a) = p;
		ans += min(n, a) * b;
		n -= min(n, a);
	}
	cout << ans << endl;
	return 0;
}