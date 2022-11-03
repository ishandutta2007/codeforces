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
const int N = 3e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i * i <= n; i++)
	{
		if (n%i == 0) v.push_back(i), v.push_back(n / i);
	}
	LL ans = 0;
	LL minv = LLONG_MAX;
	for (auto &x : v)
	{
		int s = n / x;
		for (auto &y : v)
		{
			if (s%y == 0)
			{
				ans = max(ans, LL(x + 2)*(y + 2)*(s / y + 1));
				minv = min(minv, LL(x + 2)*(y + 2)*(s / y + 1));
			}
		}
	}
	cout << minv - n << ' ' << ans - n << endl;
	return 0;
}