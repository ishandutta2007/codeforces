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
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) sum = max(sum, 0);
		sum += a[i];
		if (sum > d)
		{
			puts("-1");
			return 0;
		}
	}
	sum = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			if (sum < 0) ans++, sum = d;
		}
		sum += a[i];
		sum = min(sum, d);
	}
	cout << ans << endl;
	return 0;
}