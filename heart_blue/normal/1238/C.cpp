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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int h, n;
		cin >> h >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[n + 1] = a[n + 2] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > a[i + 1])
			{
				a[i] = a[i + 1] + 1;
			}
			if (a[i] <= 2) break;
			if (a[i + 2] + 2 == a[i])
			{
				i++;
			}
			else
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}