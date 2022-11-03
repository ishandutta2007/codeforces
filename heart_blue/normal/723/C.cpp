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
const int N = 1e4 + 10;

int a[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int avg = n / m;
	int count = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= m) cnt[a[i]]++;
		else count++;
	}
	ans = count;
	for (int i = 0; i < n; i++)
	{
		if (count == 0) break;
		if (a[i] > m)
		{
			for (int j = 1; j <= m;j++)
			{
				if (cnt[j] < avg)
				{
					cnt[j]++;
					a[i] = j;
					count--;
					break;
				}
			}
		}
	}
	ans -= count;
	for (int i = 1; i <= m; i++)
	{
		if (cnt[i] < avg)
		{
			for (int j = 0; j < n; j++)
			{
				if (cnt[a[j]] > avg)
				{
					cnt[i]++;
					cnt[a[j]]--;
					a[j] = i;
					ans++;
				}
				if (cnt[i] == avg) break;
			}
		}
	}
	cout << avg << ' ' << ans << endl;
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}