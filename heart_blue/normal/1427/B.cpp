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
const int N = 3e5 + 10;
char str[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", str);
		vector<pair<int, int>> vp1, vp2;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'W') continue;
			int j = i;
			while (j < n && str[j] == 'L') j++;
			j--;
			if (i == 0 || j == n - 1) vp2.emplace_back(i, j);
			else vp1.emplace_back(j - i + 1, i);
			i = j;
		}
		sort(vp1.begin(), vp1.end());
		for (auto& p : vp1)
		{
			int l = p.second;
			int len = min(k, p.first);
			int r = l + len - 1;
			for (int i = l; i <= r; i++)
				str[i] = 'W';
			k -= len;
		}
		for (auto& p : vp2)
		{
			int l, r;
			tie(l, r) = p;
			if (l == 0)
			{
				for (int i = r; i >= l && k > 0; k--,i--)
					str[i] = 'W';
			}
			else
			{
				for (int i = l; i <= r && k > 0; i++, k--)
					str[i] = 'W';
			}
		}
		int ans = str[0] == 'W';
		for (int i = 1; i < n; i++)
		{
			if (str[i] == 'W')
			{
				if (str[i - 1] == 'W')
					ans += 2;
				else
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}