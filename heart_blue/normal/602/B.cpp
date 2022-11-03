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
const int N = 1e5 + 10;
int cnt[N];
int a[N];
bool check(int x, int tot)
{
	int dif, sum;
	dif = sum = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		if (cnt[i]) dif++;
		sum += cnt[i];
	}
	return dif <= 2 && sum == tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(cnt, 0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int r = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (check(a[i], r - i))
		{
			ans = max(ans, r - i);
			if (r == n) break;
			cnt[a[r++]]++;
		}
		cnt[a[i]]--;
	}
	cout << ans << endl;
	return 0;
}