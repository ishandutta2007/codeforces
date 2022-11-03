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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e8 + 7;
const int N = 2e5 + 10;
bool solve(int n)
{
	vector<int> v(n * 4);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	int l = 0, r = v.size() - 1;
	while (l <= r)
	{
		if (v[l] != v[l + 1] || v[r] != v[r - 1]) return false;
		int res = v[l] * v[r];
		if (ans == 0) ans = res;
		if (ans != res) return false;
		l += 2, r -= 2;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		if (solve(n)) puts("YES");
		else puts("NO");
	}
	return 0;
}