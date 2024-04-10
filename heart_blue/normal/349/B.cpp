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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e1 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int key = 0;
	int maxn = 0;
	int minn = INF;
	for (int i = 1; i <= 9; i++)
	{
		cin >> a[i];
		minn = min(minn, a[i]);
		if (n / a[i] >= maxn)
		{
			maxn = n / a[i];
			key = i;
		}
	}
	if (maxn == 0) puts("-1");
	else
	{
		while (maxn--)
		{
			for (int i = 9; i > 0; i--)
			{
				if (n < a[i]) continue;
				if ((n - a[i]) / minn == maxn)
				{
					putchar(i + '0');
					n -= a[i];
					continue;

				}
			}
		}
	}

	return 0;
}