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
const int N = 2e5 + 10;
int a[N];
int b[N];
int sum1[N];
int sum2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v;
	for (int i = 1; i * i <= k; i++)
	{
		if (k % i) continue;
		v.push_back(i);
		if (i != k / i) v.push_back(k / i);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1) a[i] += a[i - 1];
		sum1[a[i]]++;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		if (b[i] == 1) b[i] += b[i - 1];
		sum2[b[i]]++;
	}
	for (int i = n; i >= 1; i--) sum1[i] += sum1[i + 1];
	for (int i = m; i >= 1; i--) sum2[i] += sum2[i + 1];
	LL ans = 0;
	for (auto& x : v)
	{
		if (x > n) continue;
		if (k / x > m) continue;
		ans += 1LL * sum1[x] * sum2[k / x];
	}
	cout << ans << endl;
	return 0;
}