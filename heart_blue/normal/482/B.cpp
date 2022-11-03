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
const int N = 1e5 + 10;
int l[N];
int r[N];
int q[N];
int ans[N];
int sum[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, 0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i] >> q[i];
	}
	for (int o = 0; o < 30; o++)
	{
		MEM(sum, 0);
		MEM(cnt, 0);
		for (int i = 1; i <= m; i++)
		{
			if (q[i] >> o & 1)
			{
				cnt[l[i]]++;
				cnt[r[i] + 1]--;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cnt[i] += cnt[i - 1];
			sum[i] += sum[i - 1];
			if (cnt[i])
			{
				sum[i]++;
				ans[i] |= 1 << o;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (q[i] >> o & 1) continue;
			int L = l[i];
			int R = r[i];
			if (R - L + 1 == sum[R] - sum[L - 1])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}