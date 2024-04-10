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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int ans[N];
inline LL getans(vector<int>& v, int k)
{
	LL ans = 1;
	for (int i = 0; i < k; i++) ans *= v[i];
	return ans;
}
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
		vector<int> a1, a2, b1, b2;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] > 0) a1.push_back(a[i]), a2.push_back(a[i]);
			if (a[i] < 0) b1.push_back(a[i]), b2.push_back(a[i]);
			if (a[i] == 0) cnt = 1;
		}
		sort(a1.begin(), a1.end());
		sort(a2.rbegin(), a2.rend());
		sort(b1.begin(), b1.end());
		sort(b2.rbegin(), b2.rend());
		LL ans = LLONG_MIN;
		if (cnt) ans = 0;
		for (int i = 0; i <= 5; i++)
		{
			if (i > a1.size()) break;
			for (int j = 0; j <= 5; j++)
			{
				if (j > a2.size()) break;
				if (i + j > 5) continue;
				if (i + j > a1.size()) continue;
				for (int k = 0; k <= 5; k++)
				{
					if (k > b1.size()) continue;
					if (i + j + k > 5) continue;
					int t = 5 - i - j - k;
					if (t > b2.size()) continue;
					if (k + t > b1.size()) continue;
					LL res = 1;
					ans = max(ans, getans(a1, i) * getans(a2, j) * getans(b1, k) * getans(b2, t));
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}