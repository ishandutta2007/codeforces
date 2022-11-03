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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int check(int l, int r, int mask)
{
	if (l == r) return 0;
	int mid = (l + r) / 2;
	mask >>= 1;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = l; i <= mid; i++) cnt1 += (a[i] & mask) > 0;
	for (int i = mid + 1; i <= r; i++) cnt2 += (a[i] & mask) > 0;
	if (cnt1 > 0 && cnt2 > 0) return -1;
	int res1 = check(l, mid, mask);
	int res2 = check(mid + 1, r, mask);
	if (res1 == -1 || res2 == -1) return -1;
	else return res1 + res2 + (cnt1 > 0);

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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i]--;
		}
		printf("%d\n", check(1, n, n));
	}
	return 0;
}