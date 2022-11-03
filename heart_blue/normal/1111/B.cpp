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
const int N = 50 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k, m;
	cin >> n >> k >> m;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.rbegin(), v.rend());
	LL sum = 0;
	double ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if (m < n - i - 1) continue;
		ans = max(ans, (sum + min(m - (n - i - 1), k*(i + 1))) / (i + 1.0));
	}
	printf("%.15f\n", ans);
	return 0;
}