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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	cin >> n >> p;
	vector<string> vs(n);
	for (auto &str : vs) cin >> str;
	reverse(vs.begin(), vs.end());
	LL ans = 0;
	LL cur = 0;
	for (auto &str : vs)
	{
		if (str == "halfplus") ans += cur*p + p/2, cur = 2 * cur + 1;
		else ans += cur*p, cur = 2 * cur;
	}
	cout << ans << endl;
	return 0;
}