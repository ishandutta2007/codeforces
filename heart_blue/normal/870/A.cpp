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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v1(n), v2(m);
	for (auto &x : v1) cin >> x;
	for (auto &y : v2) cin >> y;
	int ans = 99;
	for (auto &x : v1)
	{
		for (auto &y : v2)
		{
			if (x == y) ans = min(ans, x);
			else ans = min(ans, min(x * 10 + y, y * 10 + x));
		}
	}
	cout << ans << endl;
	return 0;
}