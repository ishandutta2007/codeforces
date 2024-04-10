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
const int N = 5e3 + 10;
int a[N];
int ans[N];
int f[N];
void refrain(int &n)
{
	for (int i = 2; i*i <= abs(n); i++)
	{
		while (n % (i*i) == 0) n /= i * i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		refrain(a[i]);
		if (a[i] == 0) continue;
		if (!mc.count(a[i])) mc[a[i]] = k++;
		a[i] = mc[a[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		int flag = 0;
		int cnt = 0;
		MEM(f, 0);
		for (int j = i; j <= n; j++)
		{
			if (a[j] == 0) flag = 1;
			else
			{
				if (f[a[j]] == 0) cnt++;
				f[a[j]]++;
			}
			if (flag) ans[max(1, cnt)]++;
			else ans[cnt]++;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}