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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n, r;
		scanf("%d%d", &n, &r);
		LL tot = 0;
		vector<int> v(n);
		for (auto& x : v) scanf("%d", &x);
		sort(v.rbegin(), v.rend());
		int pre = 0;
		for (auto& x : v)
		{
			if (x == pre) continue;
			pre = x;
			if (x - tot > 0) tot += r;
		}
		printf("%lld\n", tot / r);
	}
	return 0;
}