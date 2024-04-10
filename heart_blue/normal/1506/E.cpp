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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int ans1[N];
int ans2[N];
int flag[N];
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] != a[i - 1]) ans1[i] = ans2[i] = a[i];
			else ans1[i] = ans2[i] = 0;
		}
		memset(flag, 0, sizeof(int) * (n + 1));
		set<int> s1, s2;
		int cur = 1;
		for (int i = 1; i <= n; i++)
		{
			if (ans1[i])
			{
				while (cur < ans1[i])
				{
					s1.insert(cur);
					s2.insert(cur);
					cur++;
				}
				cur = a[i] + 1;
			}
			else
			{
				ans1[i] = *s1.begin();
				ans2[i] = *s2.rbegin();
				s1.erase(*s1.begin());
				s2.erase(*s2.rbegin());
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans1[i], " \n"[i == n]);
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans2[i], " \n"[i == n]);
	}
	return 0;
}