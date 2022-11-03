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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> vp(n);
	for (auto &p : vp) cin >> p.first >> p.second;
	sort(vp.begin(), vp.end());
	int o = 1;
	dp[0] = 0;
	int maxn = 0;
	for (auto &p : vp)
	{
		int pre = lower_bound(vp.begin(), vp.end(), make_pair(p.first - p.second, 0)) - vp.begin();
		dp[o] = dp[pre] + 1;
		maxn = max(dp[o], maxn);
		o++;
	}
	cout << n - maxn << endl;
	return 0;
}