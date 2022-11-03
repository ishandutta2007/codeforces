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
int b[N];
int fail[N];
void getfail(int a[], int n)

{
	int j = -1;
	fail[0] = -1;
	for (int i = 1; i < n; i++)
	{
		while (j >= 0 && a[j + 1] != a[i]) j = fail[j];
		if (a[j + 1] == a[i])
		{
			j++;
		}
		fail[i] = j;
	}
}
int getans(int n, int m)
{
	int j = -1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (j >= 0 && a[j + 1] != b[i]) j = fail[j];
		if (a[j + 1] == b[i])
		{
			j++;
			if (j == m - 1)
			{
				ans++;
				j = fail[j];
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	if (m == 1)
	{
		cout << n << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i + 1 < n; i++) b[i] = b[i + 1] - b[i];
	for (int i = 0; i + 1 < m; i++) a[i] = a[i + 1] - a[i];
	n--, m--;
	getfail(a, m);
	cout << getans(n, m) << endl;
	return 0;
}