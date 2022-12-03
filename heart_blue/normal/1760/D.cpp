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
const int N = 1e3 + 10;

bool solve()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (auto& x : v) scanf("%d", &x);
	if (n == 1) return true;
	int i = 1;
	for (i = 1; i < n; i++)
	{
		if (v[i] > v[i - 1])
			break;
	}
	for (i = i; i < n; i++)
	{
		if (v[i] < v[i - 1])
			break;
	}
	return i == n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}