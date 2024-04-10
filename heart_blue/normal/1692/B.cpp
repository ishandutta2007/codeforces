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
#include <complex>
#include <random>
#include <chrono>
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
		map<int, int> mc;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		int tot = 0;
		for (auto& [val, cnt] : mc)
		{
			while (cnt > 2) cnt -= 2;
			if (cnt == 2) tot++;
		}
		if (tot % 2 == 0) printf("%d\n", mc.size());
		else printf("%d\n", mc.size() - 1);
	}
	return 0;
}