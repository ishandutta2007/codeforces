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
const int N = 3e5 + 10;
int a[N];
int b[N];
int ans1[N];
int ans2[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = n, j = n; i >= 1; i--)
		{
			ans1[i] = b[i] - a[i];
			j = min(j, i - 1);
			while (j >= 1 && a[j] <= b[j + 1] && a[i] <= b[j]) j--;
			j++;
			ans1[i] = b[j] - a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			ans2[i] = b[i] - a[i];
			int j = i + 1;
			while (j <= n && a[j] <= b[j - 1]) j++;
			j--;
			while (i <= j)
			{
				ans2[i] = b[j] - a[i];
				i++;
			}
			i = j;
		}
		for (int i = 1; i <= n; i++) printf("%d%c", ans1[i], " \n"[i == n]);
		for (int i = 1; i <= n; i++) printf("%d%c", ans2[i], " \n"[i == n]);
	}
	return 0;
}