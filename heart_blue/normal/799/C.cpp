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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<pair<int, int>> vc, vd;
void del(map<int, int> &m, int x)
{
	m[x] --;
	if (m[x] == 0) m.erase(x);
}
pair<int, int> solve(vector<pair<int, int>> &v, int &tot)
{
	if (v.empty()) return { 0,0 };
	if (v.size() == 1) return { 0,v[0].second };
	sort(v.begin(), v.end());
	map<int, int> m;
	for (auto &p : v) m[p.second]++;
	int ans2 = m.rbegin()->first;
	int ptr = v.size() - 1;
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		auto &p = v[i];
		while (ptr >= 0 && v[ptr].first + p.first > tot)
		{
			del(m, v[ptr--].second);
		}
		if (ptr == i) del(m, v[ptr--].second);
		if (m.empty()) continue;
		if (ptr > i) del(m, p.second);
		auto o = *m.rbegin();
		ans = max(ans, o.first + p.second);
		if (ptr > i) m[p.second]++;
	}
	return { ans,ans2 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, c, d;
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++)
	{
		int b, p;
		char type;
		cin >> b >> p >> type;
		if (type == 'C')
		{
			if (p > c) continue;
			vc.push_back({ p,b });
		}
		else
		{
			if (p > d) continue;
			vd.push_back({ p,b });
		}
	}
	auto p1 = solve(vc, c);
	auto p2 = solve(vd, d);
	int ans = max(p1.first, p2.first);
	if (LL(p1.second)* p2.second != 0) ans = max(p1.second + p2.second, ans);
	cout << ans << endl;
	return 0;
}