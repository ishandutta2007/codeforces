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
const int N = 2e2 + 10;
int a[N];
int n, k;
int check(int l, int r)
{
	vector<int> v1, v2;
	for (int i = 1; i < l; i++) v2.push_back(a[i]);
	for (int i = r + 1; i <= n; i++) v2.push_back(a[i]);
	for (int i = l; i <= r; i++) v1.push_back(a[i]);
	sort(v2.rbegin(), v2.rend());
	int o = min(k, (int)v2.size());
	for (int i = 0; i < o; i++) v1.push_back(v2[i]);
	sort(v1.rbegin(), v1.rend());
	int sum = 0;
	for (int i = 0; i <= r - l; i++) sum += v1[i];
	return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = -INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			ans = max(ans, check(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}