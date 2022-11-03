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
const int N = 5e5 + 10;
int a[N];
LL cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cnt[0] = 0;
	LL sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	LL avg = sum / 3;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		cnt[i] = cnt[i - 1];
		if (sum == avg) cnt[i]++;
	}
	LL ans = 0;
	sum = 0;
	for (int i = n; i > 1; i--)
	{
		sum += a[i];
		if (sum == avg)
		{
			ans += cnt[i - 2];
		}
	}
	cout << ans << endl;
	return 0;
}