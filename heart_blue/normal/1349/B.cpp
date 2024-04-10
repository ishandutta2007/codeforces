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
int a[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n == 1)
		{
			if (a[1] == k) puts("yes");
			else puts("no");
			continue;
		}
		int ok = 0;
		int cur = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == k && cur == 0 && cnt > 0) ok = 1;
			if (a[i] == k && cur > 0) ok = 1;
			if (cur == 0 && cnt > 0 && a[i] >= k) cur = INF;
			if (a[i] >= k) cur++;
			else cur--;
			cnt++;
			if (cur < 0) cur = 0, cnt = 0;
			if (cur > 1) cur = INF;
		}
		cur = 0;
		cnt = 0;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] == k && cur == 0 && cnt > 0) ok = 1;
			if (a[i] == k && cur > 0) ok = 1;
			if (cur == 0 && cnt > 0 && a[i] >= k) cur = INF;
			if (a[i] >= k) cur++;
			else cur--;
			cnt++;
			if (cur < 0) cur = 0, cnt = 0;
			if (cur > 1) cur = INF;
		}
		if (ok) puts("yes");
		else puts("no");
	}
	return 0;
}