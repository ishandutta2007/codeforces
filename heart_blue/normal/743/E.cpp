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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[9][N][N];
int b[N];
int cnt[N];
void init()
{
	cnt[0] = 0;
	for (int i = 1; i < (1 << 8); i++)
	{
		cnt[i] = cnt[i - (i&-i)] + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n;
	init();
	cin >> n;
	MEM(a, 0x1f);
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int o = 1; o <= 8; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			int cur = 1;
			a[o][i][0] = i - 1;
			for (int j = i; j <= n; j++)
			{
				if (b[j] == o) a[o][i][cur++] = j;
			}
		}
	}
	int l = 0;
	int r = n / 8;
	int ans = 0;
	while (l <= r)
	{
		vector<int> v;
		for (int i = 1; i <= 8; i++) v.push_back(i);
		int flag = 0;
		int mid = (l + r) / 2;
		for (int o = 0; o < (1 << 8); o++)
		{
			sort(v.begin(), v.end());
			do
			{
				int cur = 0;
				for (int i = 0; i < 8; i++)
				{
					if (cur + 1 > n)
					{
						cur = INF;
						break;
					}
					int x = mid;
					if ((1 << i)&o) x++;
					cur = a[v[i]][cur + 1][x];
				}
				if (cur <= n)
				{
					flag = 1;
					ans = max(ans, cnt[o] + mid * 8);
					break;
				}
			} while (next_permutation(v.begin(), v.end()));
		}
		if (flag) l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}