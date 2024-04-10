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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int a[N];
vector<pair<int, int>> vp;
map<int, int> mc;
void add(int x)
{
	if (x == 0) return;
	mc[x]++;
}
void del(int x)
{
	if (x == 0) return;
	mc[x]--;
	if (mc[x] == 0) mc.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	sort(vp.begin(), vp.end());
	set<int> s;
	s.insert(0);
	s.insert(n + 1);
	add(n);
	pair<int, int> ans = { 0,0 };
	vector<int> v;
	for (auto &p : vp) v.push_back(p.first + 1);
	reverse(v.begin(), v.end());
	for(auto &x : v)
	{
		while (!vp.empty() && vp.back().first >= x)
		{
			int px = vp.back().second;
			vp.pop_back();
			auto iter = s.lower_bound(px);
			int r = *iter;
			int l = *(--iter);
			del(r - l - 1);
			add(px - l - 1);
			add(r - px - 1);
			s.insert(px);
		}
		if (mc.size() == 1)
		{
			ans = max(ans, make_pair(mc.begin()->second, -x));
		}
	}
	printf("%d\n", -ans.second);
	return 0;
}