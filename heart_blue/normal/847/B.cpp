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
const int N = 2e5 + 10;
vector<vector<int>> vs;
bool cmp(const vector<int> &v1, const vector<int> &v2)
{
	return v1.back() <= v2.back();
}
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (vs.empty() || -vs.back().back() > x)
		{
			vs.push_back({ -x });
			a[vs.size()] = -x;
		}
		else
		{
			int o = lower_bound(a + 1, a + vs.size() + 1, -x) - (a + 1);
			vs[o].push_back(-x);
			a[o + 1] = -x;
		}
	}
	for (auto &v : vs)
	{
		for (auto &x : v) cout << -x << ' ';
		cout << '\n';
	}
	return 0;
}