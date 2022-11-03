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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		tot += x;
		a[x] = 1;
	}
	ans = tot;
	for (int i = 1; i <= 100; i++)
	{
		if (a[i] == 0) continue;
		for (int j = 1; j <= 100; j++)
		{
			if (a[j] == 0) continue;
			if (i == j) continue;
			for (int k = 1; k <= i; k++)
			{
				if (i%k) continue;
				ans = min(ans, tot - i - j + i / k + j * k);
			}
		}
	}
	cout << ans << endl;
	return 0;
}