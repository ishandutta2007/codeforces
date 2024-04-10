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
const int M = 2e2 + 10;
int a[N];
int tot[N];
int cnt[M][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], tot[a[i]]++;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x][0]++;
		cnt[x][a[i]]++;
	}
	int ans = INF;
	int cost = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int tmp = 0;
		int cur = tot[i];
		if (cur == 0) continue;
		int rest = max(0, n - cur - (cur - 1));
		int o = 0;
		for (int j = 1; j < M; j++)
		{
			int r = cnt[j][0] - cnt[j][i];
			tmp += min(r, rest)*j;
			rest -= min(r, rest);
			cnt[j][0] -= cnt[j][i];
			n -= cnt[j][i];
			o += cnt[j][i] * j;
		}
		ans = min(ans, tmp + cost);
		cost += o;
	}
	cout << ans << endl;
	return 0;
}