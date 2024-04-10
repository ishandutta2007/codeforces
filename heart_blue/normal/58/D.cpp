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
const int N = 1e2 + 10;
vector<string> vs[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = INF;
	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		int len = str.length();
		vs[len].push_back(str);
		l = min(l, len);
		r = max(r, len);
	}
	string key;
	cin >> key;
	int sum = (l + r);
	typedef tuple<string, int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = l; i <= r; i++)
		sort(vs[i].rbegin(), vs[i].rend());
	for (int i = l; i <= r; i++)
	{
		int a = i;
		int b = sum - i;
		if (vs[i].empty()) continue;
		if (a != b)
		{
			pq.emplace(vs[a].back() + key + vs[b].back(), a, (int)vs[a].size());
		}
		else
		{
			auto& s1 = *vs[a].rbegin();
			auto& s2 = *(vs[a].rbegin() + 1);
			pq.emplace(s1 + key + s2, a, (int)vs[a].size());
		}
	}
	while (!pq.empty())
	{
		auto [str, id, sz] = pq.top();
		pq.pop();
		if (vs[id].size() != sz) continue;
		puts(str.c_str());
		int a = id;
		int b = sum - a;
		vs[a].pop_back();
		vs[b].pop_back();
		if (vs[a].empty()) continue;
		if (a != b)
		{
			pq.emplace(vs[a].back() + key + vs[b].back(), a, (int)vs[a].size());
			pq.emplace(vs[b].back() + key + vs[a].back(), b, (int)vs[b].size());
		}
		else
		{
			auto& s1 = *vs[a].rbegin();
			auto& s2 = *(vs[a].rbegin() + 1);
			pq.emplace(s1 + key + s2, a, (int)vs[a].size());
		}
	}
	return 0;
}