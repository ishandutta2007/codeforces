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
const int N = 2e5 + 10;
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
		vector<int> v1(n), v2(n);
		for (auto& x : v1) scanf("%d", &x);
		for (auto& x : v2) scanf("%d", &x);
		int maxv = 0;
		for (int i = 0; i < n; i++)
			maxv = max(maxv, v1[i] - v2[i]);
		for (int i = 0; i < n; i++)
			v1[i] = max(0, v1[i] - maxv);
		if (v1 == v2) puts("YES");
		else puts("NO");
	}
	return 0;
}