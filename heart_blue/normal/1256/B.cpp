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
const int N = 2e2 + 10;
int flag[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		MEM(flag, 0);
		while (1)
		{
			int cnt = 0;
			for (int i = n; i > 1; i--)
			{
				if (flag[i] == 0 && a[i] < a[i - 1])
				{
					swap(a[i], a[i - 1]);
					flag[i] = 1;
					cnt++;
				}
			}
			if (!cnt) break;
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}