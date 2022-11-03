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
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
bool solve(vector<int>& v, int n, int m)
{
	vector<int> key;
	for (auto& x : v)
	{
		if (x / n <= 1) continue;
		key.push_back(x / n);
	}
	sort(key.rbegin(), key.rend());
	for (auto& x : key)
	{
		if (m == 1)
		{
			return key[0] >= 3;
		}
		m -= x;
		if (m <= 0) return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> v(k);
		for (auto& x : v)
			scanf("%d", &x);
		if (solve(v, n, m) || solve(v, m, n)) puts("Yes");
		else puts("No");
	}
	return 0;
}