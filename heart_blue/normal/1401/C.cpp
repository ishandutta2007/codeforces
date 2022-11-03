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
const int N = 2e5 + 10;
int flag[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int minv = INF;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			flag[i] = 0;
			minv = min(minv, a[i]);
		}
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] % minv == 0)
			{
				flag[i] = 1;
				v.push_back(a[i]);
			}
		}
		sort(v.rbegin(), v.rend());
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 1)
			{
				a[i] = v.back();
				v.pop_back();
			}
		}
		int ok = 1;
		for (int i = 2; i <= n; i++)
		{
			if (a[i - 1] > a[i])
				ok = 0;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}