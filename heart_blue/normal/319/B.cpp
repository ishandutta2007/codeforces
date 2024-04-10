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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = n; i > 0; i--)
	{
		int cnt = 0;
		int x = a[i];
		while (!v.empty() && v.back() < x)
		{
			dp[x] = max(dp[x] + 1, dp[v.back()]);
			v.pop_back();
		}
		v.push_back(x);
		ans = max(ans, dp[x]);
	}
	cout << ans << endl;
	return 0;
}