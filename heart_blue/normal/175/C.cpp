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
const int N = 1e5 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	vector<pair<int, int>> vp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k, c;
		cin >> k >> c;
		vp.emplace_back(c, k);
	}
	sort(vp.begin(), vp.end());

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	m++;
	a[m] = INF * INF;
	int cur = 1;
	LL ans = 0;
	LL tot = 0;
	for (auto& p : vp)
	{
		int c, k;
		tie(c, k) = p;
		while (k != 0)
		{
			LL o = min(1LL * k, a[cur] - tot);
			tot += o;
			k -= o;
			ans += o * cur * c;
			if (a[cur] == tot) cur++;
		}
	}
	cout << ans << endl;
	return 0;
}