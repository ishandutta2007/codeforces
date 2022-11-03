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
const int N = 1e6 + 10;
struct Node
{
	int x, y, pos;
	void init(int o)
	{
		cin >> x >> y;
		pos = o;
	}
	bool operator < (const Node& node) const
	{
		if (x != node.x) return x > node.x;
		return y > node.y;
	}
};
vector<Node> v;
bool check(int i, int j, int k)
{
	int s1 = v[i].x, t1 = v[i].y;
	int s2 = v[j].x, t2 = v[j].y;
	int s3 = v[k].x, t3 = v[k].y;
	if (s1 == s2 && t1 == t2) return true;
	if (s2 == s3 && t2 == t3) return true;
	return 1LL * (t3 - t2)*s3*(s1 - s2)*t1 <= 1LL * (t2 - t1)*s1*(s2 - s3)*t3;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 1; i <= n; i++) v[i - 1].init(i);
	sort(v.begin(), v.end());
	vector<int> ans;
	int x = 0, y = 0;
	for (int i = 0; i < v.size(); i++)
	{
		auto &node = v[i];
		if (x == node.x && y == node.y)
		{
			continue;
		}
		if (x >= node.x && y >= node.y)
		{
			continue;
		}
		while (ans.size() >= 2 && !check(ans[ans.size() - 2], ans[ans.size() - 1], i))
			ans.pop_back();
		ans.push_back(i);
		x = node.x;
		y = node.y;
	}
	map<pair<int, int>, int> mp;
	for (auto &x : ans)
	{
		mp[{v[x].x, v[x].y}] = 1;
	}
	ans.clear();
	for (int i = 0; i < n; i++)
	{
		if (mp.count({ v[i].x,v[i].y }))
			ans.push_back(v[i].pos);
	}
	sort(ans.begin(), ans.end());
	for (auto &x : ans)
	{
		printf("%d ", x);
	}
	return 0;
}