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
vector<LL> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	LL ans = 0;
	for (int i = 2; i <= m; i++)
	{
		ans += abs(a[i] - a[i - 1]);
		if (a[i] != a[i - 1])
		{
			v[a[i]].push_back(a[i - 1]);
			v[a[i - 1]].push_back(a[i]);
		}
	}
	LL maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!v[i].empty())
		{
			sort(v[i].begin(), v[i].end());
			LL tot = 0;
			LL s = 0;
			for (auto &x : v[i]) tot += abs(i - x), s += x;
			int sz = v[i].size();
			LL sum = 0;
			for (int j = 0; j < sz; j++)
			{
				LL tmp = j*v[i][j] - sum + (s - sum) - (sz - j)*v[i][j];
				maxv = max(maxv, max(0LL, tot - tmp));
				sum += v[i][j];
			}
		}
	}
	cout << ans - maxv << endl;
	return 0;
}