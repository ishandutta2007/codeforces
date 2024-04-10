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
const int N = 2e2 + 10;
int pre1[N];
int pre2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(pre1, 0);
	MEM(pre2, 0);
	int n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		pre1[i] = pre1[i - 1] + x;
		sum1 += x;
	}
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		pre2[i] = pre2[i - 1] + x;
		sum2 += x;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ans = min(ans, a[i] + a[j] + pre1[i] + pre1[j] - pre2[i] - pre2[j] + sum2 + sum2);
		}
	}
	cout << ans << endl;
	return 0;
}