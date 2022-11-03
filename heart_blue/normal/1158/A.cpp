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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v1(n), v2(m);
	for (auto& x : v1) cin >> x;
	for (auto& x : v2) cin >> x;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1.back() > v2.front()) puts("-1"), exit(0);
	LL ans = 0;
	for (auto& x : v1) ans += 1LL * m * x;
	int ptr = n - 1;
	int cnt = m - 1;
	for (int i = 0; i < m; i++)
	{
		if (v2[i] == v1.back()) continue;
		if (cnt == 0) cnt = m - 1, ptr--;
		cnt--;
		ans += (v2[i] - v1[ptr]);
	}
	cout << ans << endl;
	return 0;
}