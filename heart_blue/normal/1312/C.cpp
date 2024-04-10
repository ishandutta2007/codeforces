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
		int n, k;
		scanf("%d%d", &n, &k);
		priority_queue<LL> pq;
		while (n--)
		{
			LL x;
			scanf("%lld", &x);
			pq.emplace(x);
		}
		LL o = 1;
		while (o < pq.top()) o *= k;
		while (pq.top() != 0 && o > 0)
		{
			LL x = pq.top();
			pq.pop();
			if (x >= o) x -= o;
			pq.push(x);
			o /= k;
		}
		if (pq.top() == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}