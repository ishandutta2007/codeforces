#pragma comment(linker, "/STACK:102400000,102400000")
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
		int n, k1, k2;
		scanf("%d%d%d", &n, &k1, &k2);
		vector<int> v1(k1), v2(k2);
		for (auto& x : v1) scanf("%d", &x);
		for (auto& x : v2) scanf("%d", &x);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if (v1.back() > v2.back()) puts("YES");
		else puts("NO");
	}


	return 0;
}