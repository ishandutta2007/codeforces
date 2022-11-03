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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vp.resize(n);
	for (auto &p : vp)
	{
		cin >> p.first >> p.second;
	}
	sort(vp.begin(), vp.end());
	int maxv = -INF;
	int p = 0;
	int ans = 0;
	while (p < vp.size())
	{
		int o = upper_bound(vp.begin(), vp.end(), make_pair(vp[p].first, (int)INF)) - vp.begin();
		int tmp = -INF;
		while (p < o)
		{
			if (maxv > vp[p].second) ans++;
			tmp = max(tmp, vp[p].second);
			p++;
		}
		maxv = max(maxv, tmp);
	}
	cout << ans << endl;
	return 0;
}