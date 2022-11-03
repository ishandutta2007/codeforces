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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 20;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	int minv = INF;
	int maxv = 0;
	for (auto &x : v)
	{
		cin >> x;
		cnt[x]++;
		minv = min(minv, x);
		maxv = max(maxv, x);
	}
	for (int i = N - 1; i > 0; i--)
	{
		cnt[i - 1] += cnt[i];
	}
	int tot = 0;
	int o = minv + 1;
	int ans = 0;
	while (o <= maxv)
	{
		tot += cnt[o];
		if (tot > k)
		{
			ans++;
			tot = cnt[o];
		}
		o++;
	}
	if (tot > 0) ans++;
	cout << ans << endl;
	return 0;
}