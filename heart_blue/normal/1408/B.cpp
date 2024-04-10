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
const int N = 4e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 2; i <= n; i++)
		{
			cnt += a[i] > a[i - 1];
		}
		if (k == 1)
		{
			if (cnt == 0) puts("1");
			else puts("-1");
		}
		else
		{
			printf("%d\n", max(1, (cnt + k - 2) / (k - 1)));
		}
	}
	return 0;
}