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
		vector<int> v(n);
		LL ans = 0;
		for (auto& x : v)
		{
			scanf("%d", &x);
			ans += x / k;
			x %= k;
		}
		sort(v.rbegin(), v.rend());
		for (int i = 0; i + 1 < v.size(); i++)
		{
			while (v.size() > i + 2 && v[i] + v.back() < k)
				v.pop_back();
			if (v[i] + v.back() >= k)
			{
				ans++;
				v.pop_back();
			}
			else
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}