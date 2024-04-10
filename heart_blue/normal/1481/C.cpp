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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
vector<int> v[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
		int last = -1;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] == c[m])
			{
				last = i;
				break;
			}
		}
		if (last == -1)
		{
			puts("NO");
			continue;
		}
		
		for (int i = 1; i <= n; i++) v[i].clear();
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != b[i])
				v[b[i]].push_back(i), cnt++;
		}
		if (!v[b[last]].empty())
		{
			last = v[b[last]].front();
		}
		for (int i = 1; i <= m; i++)
		{
			int x = c[i];
			if (v[x].empty())
			{
				ans[i] = last;
			}
			else
			{
				if (v[x].back() == last) swap(v[x].back(), v[x][0]);
				ans[i] = v[x].back();
				v[x].pop_back();
				cnt--;
			}
			b[ans[i]] = x;
		}
		if (cnt != 0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= m; i++)
			printf("%d ", ans[i]);
		puts("");
		
	}
	return 0;
}