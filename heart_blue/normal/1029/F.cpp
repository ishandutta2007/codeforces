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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;

void check(vector<LL> &v, LL n)
{
	for (int i = 1; 1LL * i*i <= n; i++)
	{
		if (n%i) continue;
		v.push_back(i);
		if (n / i != i) v.push_back(n / i);
	}
	sort(v.begin(), v.end());
}
bool check(LL l, LL r, LL a, vector<LL> &v)
{
	if (l > r) swap(l, r);
	int o = upper_bound(v.begin(), v.end(), 1LL * l) - v.begin();
	if (o == 0) return false;
	return a / v[o - 1] <= r;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	LL ans = INF * INF;
	LL a, b;
	cin >> a >> b;
	n = a + b;
	vector<LL> v, v1, v2;
	check(v, n);
	check(v1, a);
	check(v2, b);
	for (auto &x : v)
	{
		if (check(x, n / x, a, v1) || check(x, n / x, b, v2))
		{
			ans = min(ans, x * 2 + n / x * 2);
		}
	}
	cout << ans << endl;
	return 0;
}