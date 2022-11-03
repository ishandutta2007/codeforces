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
const int N = 3e2 + 10;
int a[N];
int b[N];
int fail[N];
int sz[N];
void getfail(int a[], int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j > 0 && a[j + 1] != a[i]) j = fail[j];
		if (a[j + 1] == a[i]) j++;
		fail[i] = j;
	}
}
int check(int a[], int b[], int n, int m, int d)
{
	int j = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		while (j > 0 && b[j + 1] != a[i]) j = fail[j];
		if (b[j + 1] == a[i]) j++;
		if (j == m)
		{
			cnt++;
			j = 0;
		}
	}
	if (cnt <= 1) return 0;
	return d * cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<string, int> ms;
	int n;
	cin >> n;
	int k = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		if (!ms.count(str)) ms[str] = ++k;
		a[i] = ms[str];
		sz[i] = str.length();
		tot += sz[i];
	}
	tot += n - 1;
	int m = 0;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		m = 0;
		for (int j = i; j <= n; j++)
		{
			b[++m] = a[j];
			sum += sz[j];
			getfail(b, m);
			int ret = check(a, b, n, m, sum + (j - i) - (j - i + 1));
			maxv = max(maxv, ret);
		}
	}
	printf("%d\n", tot - maxv);
	return 0;
}