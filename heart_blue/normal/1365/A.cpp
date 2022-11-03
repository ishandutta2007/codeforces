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
const int N = 1e2 + 10;
int flag1[N];
int flag2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		MEM(flag1, 0);
		MEM(flag2, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int x;
				scanf("%d", &x);
				flag1[i] |= x;
				flag2[j] |= x;
			}
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++) cnt1 += flag1[i] ^ 1;
		for (int i = 1; i <= m; i++) cnt2 += flag2[i] ^ 1;
		if (min(cnt1, cnt2) & 1) puts("Ashish");
		else puts("Vivek");
	}
	return 0;
}