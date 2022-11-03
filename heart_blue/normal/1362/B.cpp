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
const int N = 2e3 + 10;
int cnt[N];
int a[N];
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
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		MEM(cnt, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cnt[a[i] ^ a[j]]++;
			}
		}
		int ans = -1;
		for (int i = 1; i < 1024; i++)
		{
			if (cnt[i] == n)
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}