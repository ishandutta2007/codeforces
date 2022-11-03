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
const int N = 1e3 + 10;

int a[N];
int ans[N];
int p[] = { 0,2,3,5,7,11,13,17,19,23,29,31 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		MEM(ans, 0);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int cur = 0;
		for (int o = 1; o <= 11; o++)
		{
			int flag = 0;
			for (int i = 1; i <= n; i++)
			{
				if (ans[i]) continue;
				if (a[i] % p[o] == 0)
				{
					flag = 1;
					ans[i] = cur + flag;
				}
			}
			cur += flag;
		}
		printf("%d\n", cur);
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}