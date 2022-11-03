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
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		l = max(l, a[i] - i);
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= l)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				a[j] = l;
			}
			break;
		}
	}
	int r = a[p - 1];
	int L = 0, R = p - 1;
	int ret = -1;
	while (L <= R)
	{
		int mid = (L + R) / 2;
		int sum = 1;
		int cnt = 0;
		int cur = mid + l;
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= mid + l)
			{
				cnt++;
				cur++;
				if (cnt >= p)
				{
					sum = 0;
					break;
				}
			}
			else
			{
				sum = 1LL * sum * (cur - a[i] + 1) % p;
				cur++;
			}
		}
		if (sum == 0) R = mid - 1;
		else ret = mid, L = mid + 1;
	}
	printf("%d\n", ret + 1);
	for (int i = 0; i <= ret; i++)
		printf("%d ", l + i);
	return 0;
}