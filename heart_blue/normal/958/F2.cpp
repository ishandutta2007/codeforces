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
const int N = 2e5 + 10;
int cnt[N];
int tot[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	int ok = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
	{
		cin >> cnt[i], sum += cnt[i];
		if (cnt[i] == 0)
			ok++;
	}
	int ptr = 1;
	int minv = INF;
	for (int i = 1; i <= n; i++)
	{
		while (ptr <= n && ok < k)
		{
			int x = a[ptr++];
			if (++tot[x] == cnt[x])
				ok++;
		}
		if (ok == k)
		{
			minv = min(minv, ptr - i);
		}
		if (tot[a[i]]-- == cnt[a[i]])
			ok--;
	}
	if (minv == INF) puts("-1");
	else printf("%d\n", minv - sum);
	return 0;
}