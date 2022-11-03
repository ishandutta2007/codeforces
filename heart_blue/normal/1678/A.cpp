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
const int N = 3e5 + 10;

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
		int cnt0 = count(v.begin(), v.end(), 0);
		if (cnt0 > 0)
		{
			printf("%d\n", n - cnt0);
			continue;
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (v.size() != n) printf("%d\n", n);
		else printf("%d\n", n + 1);
	}
	return 0;
}