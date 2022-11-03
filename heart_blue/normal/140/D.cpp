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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int cur = 10;
	int tot = 0;
	int ans = 0;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (auto &x : v)
	{
		cur += x;
		if (cur > 720) break;
		tot++;
		ans += max(0, cur - 360);
	}
	cout << tot << ' ' << ans << endl;
	return 0;
}