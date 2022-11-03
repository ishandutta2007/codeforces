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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d, k;
	scanf("%d%d%d", &n, &d, &k);
	vector<int> v1, v2;
	LL tot = 0;
	LL ans = 0;
	LL sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x > k) v2.push_back(x);
		else v1.push_back(x), tot += x;
	}
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	ans = tot;
	int sz1 = v1.size();
	for (int i = 0; i < v2.size(); i++)
	{
		int cost = i * d;
		cost -= v2.size() - i - 1;
		sum += v2[i];
		if (cost <= 0)
		{
			ans = max(ans, sum + tot);
		}
		else
		{
			if (sz1 < cost) break;
			while (v1.size() > sz1 - cost)
			{
				tot -= v1.back();
				v1.pop_back();
			}
			ans = max(ans, tot + sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}