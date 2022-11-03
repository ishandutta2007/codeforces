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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int g, d, f;
	scanf("%d%d%d", &g, &d, &f);
	vector<int> a(g), b(d), c(f);
	for (auto& x : a) scanf("%d", &x);
	for (auto& x : b) scanf("%d", &x);
	for (auto& x : c) scanf("%d", &x);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	LL ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			int ptr1 = j;
			int ptr2 = 0;
			for (int k = 0; k < c.size(); k++)
			{
				int x = a[i], y = b[j], z = c[k];
				int minv = min({ x,y,z });
				if (max({ x,y,z }) > 2 * minv) continue;
				ptr2 = max(ptr2, k);
				while (ptr1 < b.size() && b[ptr1] <= 2 * minv) ptr1++;
				while (ptr2 < c.size() && c[ptr2] <= 2 * minv) ptr2++;
				int cnt1 = max(0, ptr1 - j - 1);
				int cnt2 = max(0, ptr2 - k - 1);
				ans += 1LL * cnt1 * cnt2 * (cnt2 - 1) / 2;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}