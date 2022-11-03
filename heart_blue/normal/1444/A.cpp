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
const int N = 2e3 + 10;
vector<int> check(LL p)
{
	vector<int> ret;
	for (int i = 2; i * i <= p; i++)
	{
		if (p % i) continue;
		ret.push_back(i);
		while (p % i == 0) p /= i;
	}
	if (p > 1) ret.push_back(p);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL p, q;
		scanf("%lld%lld", &p, &q);
		if (p % q)
		{
			printf("%lld\n", p);
		}
		else
		{
			LL ans = 0;
			vector<int> v = check(q);
			for (auto& x : v)
			{
				LL a = p;
				while (a % q == 0) a /= x;
				ans = max(ans, a);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}