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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 0) sum1++;
		else sum2++;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		int x = 0, y = 0;
		for (int j = i; j <= n; j += k)
		{
			if (a[j] > 0) x++;
			else y++;
		}
		ans = max(ans, abs(sum1 - x - sum2 + y));
	}
	cout << ans << endl;
	return 0;
}