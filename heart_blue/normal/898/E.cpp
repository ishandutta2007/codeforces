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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
bool check(int x)
{
	int o = sqrt(x);
	return o * o == x;
}
vector<int> v1, v2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (check(x)) v1.push_back(x);
		else v2.push_back(x);
	}
	LL ans = 0;
	if (v1.size() > n / 2)
	{
		int cnt1 = 0, cnt2 = 0;
		for (auto &x : v1)
		{
			if (x == 0) cnt2++;
			else cnt1++;
		}
		int o = v1.size() - n / 2;
		ans += min(o, cnt1);
		o -= min(o, cnt1);
		ans += min(o, cnt2) * 2;
	}
	else
	{
		vector<int> v;
		for (auto &x : v2)
		{
			int o = sqrt(x);
			v.push_back(min((o + 1)*(o + 1) - x, x - o * o));
		}
		sort(v.rbegin(), v.rend());
		int o = v2.size() - n / 2;
		while (o--) ans += v.back(), v.pop_back();
	}
	cout << ans << endl;
	return 0;
}