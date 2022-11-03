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
const int N = 3e5 + 10;
map<int, int> mc;
map<pair<int, int>, int> mp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	LL ans = 0;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) mc[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		mc[a]++;
		mc[b]++;
		if (a > b) swap(a, b);
		mp[{a, b}] ++;
	}
	for (auto& p : mc)
	{
		v.push_back(p.second);
	}
	sort(v.begin(), v.end());
	for (auto& x : v)
	{
		int pos = lower_bound(v.begin(), v.end(), k - x) - v.begin();
		ans += v.size() - pos;
		if (x * 2 >= k)
			ans--;
	}
	ans /= 2;
	for (auto& p : mp)
	{
		int a, b;
		tie(a, b) = p.first;
		int cnt = p.second;
		if (mc[a] + mc[b] >= k && mc[a] + mc[b] - cnt < k)
			ans--;
	}
	printf("%lld\n", ans);
	return 0;
}