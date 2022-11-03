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
const int N = 4e5 + 10;
bool solve(vector<int>& v, int l, int r, int x)
{
	if (l >= r) return true;
	if (v[l] == v[r]) return solve(v, l + 1, r - 1, x);
	if (x == 0) return solve(v, l, r, v[l]) || solve(v, l, r, v[r]);
	if (v[l] == x) return solve(v, l + 1, r, x);
	else if (v[r] == x) return solve(v, l, r - 1, x);
	else return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);

		if (solve(v, 0, v.size() - 1, 0)) puts("YES");
		else puts("NO");
	}
	return 0;
}