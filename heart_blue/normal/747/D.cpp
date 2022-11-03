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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	int neg = 0;
	int key = INF;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] < 0) neg++, key = min(key, i);
	}
	if (neg == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (neg > k)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> vp;
	int pre = key;
	int ans = 2 * neg;
	for (int i = key + 1; i < n; i++)
	{
		if (v[i] < 0)
		{
			vp.push_back({ i - pre - 1 });
			pre = i;
		}
	}
	int rest = n - 1 - pre;
	sort(vp.begin(), vp.end());
	k -= neg;
	int res = ans;
	for (auto &x : vp)
	{
		if (k >= x) k -= x, ans -= 2;
		res = ans;
		if (k >= rest) res = min(res, ans - 1);
	}
	if (k >= rest) res = min(res, ans - 1);
	cout << res << endl;
	return 0;
}