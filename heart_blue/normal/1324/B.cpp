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
const int N = 5e3 + 10;
int sum1[N];
int sum2[N];
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
		cin >> n;
		MEM(sum1, 0);
		MEM(sum2, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum2[a[i]]++;
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			sum2[a[i]]--;
			for (int i = 1; i <= n; i++)
			{
				if (sum1[i] && sum2[i])
				{
					flag = 1;
					break;
				}
			}
			sum1[a[i]]++;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}