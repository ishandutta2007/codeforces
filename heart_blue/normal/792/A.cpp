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
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = INF * 2;
	for (int i = 1; i < n; i++)  ans = min(ans, v[i] - v[i - 1]);
	int cnt = 0;
	for (int i = 1; i < n; i++) if (v[i] - v[i - 1] == ans) cnt++;
	cout << ans << ' ' << cnt << endl;
	return 0;
}