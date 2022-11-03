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
const int N = 1e2 + 10;
int n;
int a[N];
void check(vector<pair<int, int>> &vp, vector<pair<int, int>> &v, int o = 1)
{
	v.clear();
	for (int i = 0; i < vp.size(); i++)
	{
		if (vp[i].second == o) v.push_back({ vp[i].first,i });
	}
}
void dfs(int l, int r, vector<pair<int, int>> &vp)
{

	if (l == r)
	{
		vp.push_back({ a[l],0 });
		return;
	}
	int mid = (l + r) >> 1;
	vector<pair<int, int>> vp1, vp2;
	dfs(l, mid, vp1);
	dfs(mid + 1, r, vp2);
	vector<pair<int, int>> v1, v2, vv1, vv2;
	check(vp1, v1, 1);
	check(vp2, v2, -1);
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.rbegin(), v2.rend());
	int neg1, pos1, neg2, pos2;
	neg1 = 0, pos1 = 0, neg2 = 0, pos2 = 0;
	int sz = min(v1.size(), v2.size());
	for (int i = 0; i < sz; i++)
	{
		if (v1[i].first < v2[i].first) vp1[v1[i].second].second = 0, vp2[v2[i].second].second = 0;
	}
	check(vp1, v1, 0);
	check(vp2, v2, -1);
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.rbegin(), v2.rend());
	sz = min(v1.size(), v2.size());
	for (int i = 0; i < sz; i++)
	{
		if (v1[i].first < v2[i].first) neg1++, vp2[v2[i].second].second = 0;
	}
	check(vp1, v1, 1);
	check(vp2, v2, 0);
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.rbegin(), v2.rend());
	sz = min(v1.size(), v2.size());
	for (int i = 0; i < sz; i++)
	{
		if (v1[i].first < v2[i].first) pos2++,vp1[v1[i].second].second = 0;
	}
	check(vp1, v1, -1);
	if (!v1.empty()) sort(v1.begin(), v1.end());
	for (int i = 0; neg1 > 0 && i < v1.size(); neg1--, i++)
	{
		vp1[v1[i].second].second = -1;
	}
	check(vp2, v2, 1);
	if (!v2.empty()) sort(v2.rbegin(), v2.rend());
	for (int i = 0; pos2 > 0 && i < v2.size(); i++, pos2--)
	{
		vp2[v2[i].second].second = 1;
	}
	check(vp1, v1, 0);
	check(vp2, v2, 0);
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.rbegin(), v2.rend());
	sz = min(v1.size(), v2.size());
	for (int i = 0; i < sz; i++)
	{
		if (v1[i].first < v2[i].first) vp1[v1[i].second].second = -1, vp2[v2[i].second].second = 1;
	}
	vp.insert(vp.end(), vp1.begin(), vp1.end());
	vp.insert(vp.end(), vp2.begin(), vp2.end());
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> str >> n;
	vector<string> vs(n);
	for (auto &str : vs) cin >> str;
	for (auto &s1 : vs)
	{
		for (auto &s2 : vs)
		{
			string s = s1 + s2;
			if (s.find(str) != -1)
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}