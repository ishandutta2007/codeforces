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
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (m--)
	{
		int type, len;
		cin >> type >> len;
		if (type == 2) type = -1;
		while (!vp.empty() && vp.back().first <= len) vp.pop_back();
		vp.push_back({ len,type });
	}
	int k = vp.front().first;
	sort(a + 1, a + k + 1);
	for (int i = n; i > k; i--) ans[i] = a[i];
	int o = 1;
	int l = 1, r = k;
	for (auto &p : vp)
	{
		int len, type;
		tie(len, type) = p;
		len = (r - l + 1) - len;
		while (len--)
		{
			if (o == 1) ans[k--] = a[r--];
			else ans[k--] = a[l++];
		}
		o = type;
	}
	while (k)
	{
		if (o == 1) ans[k--] = a[r--];
		else ans[k--] = a[l++];
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}